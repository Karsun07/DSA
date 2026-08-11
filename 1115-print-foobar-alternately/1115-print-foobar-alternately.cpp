class FooBar {
private:
    int n;
    bool isFooPrinted;

    condition_variable cv;
    mutex mtx;

public:

    FooBar(int n) {
        this->n = n;
        isFooPrinted = false;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]{
                return !isFooPrinted;
            });


            // printFoo() outputs "foo"
            printFoo();


            isFooPrinted = true;


            cv.notify_all();
        }
    }


    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]{
                return isFooPrinted;
            });


            // printBar() outputs "bar"
            printBar();


            isFooPrinted = false;


            cv.notify_all();
        }
    }
};
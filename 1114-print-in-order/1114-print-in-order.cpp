class Foo {
private:
    condition_variable cv;
    mutex mt;
    bool one;
    bool two;
    bool three;
public:
    Foo() {
        one = false;
        two = false;
        three = false;
    }
    void first(function<void()> printFirst) {

        unique_lock<mutex> lock(mt);

        cv.wait(lock, [this]{
            return !one;
        });
        // printFirst() outputs "first"
        printFirst();
        one = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {

        unique_lock<mutex> lock(mt);
        cv.wait(lock, [this]{
            return one && !two;
        });
        // printSecond() outputs "second"
        printSecond();
        two = true;
        cv.notify_all();
    }



    void third(function<void()> printThird) {

        unique_lock<mutex> lock(mt);
        cv.wait(lock, [this]{
            return one && two;
        });
        // printThird() outputs "third"
        printThird();
        three = true;
        cv.notify_all();
    }
};
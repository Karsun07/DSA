class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooPrinted;
public:
    FooBar(int n) {
        this->n = n;
        fooPrinted=false;
    } 

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            unique_lock<mutex>lock(mtx);
            cv.wait(lock,[this]{
                return !fooPrinted;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            fooPrinted=true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            cv.wait(lock,[this]{
                return fooPrinted;
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooPrinted=false;
            cv.notify_all();
        }
    }
};
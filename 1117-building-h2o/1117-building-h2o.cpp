class H2O {
public:
    int hcount;
    mutex mtx;
    condition_variable cv;
    H2O() {
        hcount=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this]{
            return hcount<2;
        });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hcount++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this]{
            return hcount==2;
        });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        hcount=0;
        cv.notify_all();
    }
};
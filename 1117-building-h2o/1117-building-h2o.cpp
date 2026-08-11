class H2O {
private:
    mutex mtx;
    condition_variable cv;
    int hydrogen_count = 0;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);

        // Wait until there are less than 2 hydrogens
        while (hydrogen_count >= 2) 
        {
            // Mutex unlocked & thread enters waiting state
            cv.wait(lock);
        }

        hydrogen_count++;
        releaseHydrogen();
        
        // If two hydrogen atoms are ready, wake up oxygen
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);

        // Wait until exactly 2 hydrogens are available
        while (hydrogen_count < 2) {
            cv.wait(lock);
        }

        releaseOxygen();

        // Reset for the next water molecule
        hydrogen_count = 0;
        // Notify waiting hydrogen threads
        cv.notify_all(); 
    }
};
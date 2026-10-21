class DiningPhilosophers {
private:
    mutex mtx;

public:
    DiningPhilosophers() {
    }

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork
    ) {

        unique_lock<mutex> lock(mtx);

        // Pick both forks
        pickLeftFork();
        pickRightFork();

        // Eat
        eat();

        // Put both forks down
        putLeftFork();
        putRightFork();
    }
};
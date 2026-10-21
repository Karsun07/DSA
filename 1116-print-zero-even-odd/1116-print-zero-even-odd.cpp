class ZeroEvenOdd {
private:
    int n;
    int x;
    bool zeroPrint;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        x = 1;
        zeroPrint = false;
    }

    void zero(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this] {
                return !zeroPrint || x > n;
            });

            if (x > n) {
                cv.notify_all();
                return;
            }

            printNumber(0);

            zeroPrint = true;

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this] {
                return x > n || (zeroPrint && x % 2 == 0);
            });

            if (x > n) {
                cv.notify_all();
                return;
            }

            printNumber(x);

            x++;
            zeroPrint = false;

            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this] {
                return x > n || (zeroPrint && x % 2 == 1);
            });

            if (x > n) {
                cv.notify_all();
                return;
            }

            printNumber(x);

            x++;
            zeroPrint = false;

            cv.notify_all();
        }
    }
};
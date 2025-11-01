class MedianFinder {
public:
    priority_queue<double> maxR; 
    priority_queue<double, vector<double>, greater<double>> minL; 

    MedianFinder() {}

    void balance() {
       
        if (maxR.size() > minL.size() + 1) {
            minL.push(maxR.top());
            maxR.pop();
        } 
        else if (minL.size() > maxR.size()) {
            maxR.push(minL.top());
            minL.pop();
        }
    }

    void addNum(int num) {
       
        if (maxR.empty() || num <= maxR.top()) {
            maxR.push(num);
        } else {
            minL.push(num);
        }

        
        balance();
    }

    double findMedian() {
        int size = maxR.size() + minL.size();

        if (size % 2 == 0) {
            return (maxR.top() + minL.top()) / 2.0;
        } else {
            return maxR.top();
        }
    }
};

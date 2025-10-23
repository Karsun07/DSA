class MyCalendar {
public:
    map<int,int>intervals;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto next=intervals.lower_bound(startTime);
        if(next!=intervals.end() && next->first<endTime) return 0;
    if(next!=intervals.begin() && prev(next)->second>startTime) return 0 ;
    
        intervals[startTime]=endTime; 
        return 1;
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
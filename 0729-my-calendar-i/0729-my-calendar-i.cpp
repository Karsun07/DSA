class MyCalendar {
public:
    vector<pair<int,int>>bookings;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto &it:bookings){
            if(max(startTime,it.first)<min(endTime,it.second)){
                return 0;
            }
        }



        bookings.push_back(make_pair(startTime,endTime));
        return 1;
       
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
class MyCalendar {
public:
    vector<pair<int,int>>arr;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto it=arr.begin();it<arr.end();it++){
            int low=it->first;
            int high=it->second;
            if(startTime<high && endTime>low) return 0;
        }
        arr.push_back(make_pair(startTime,endTime));
        return 1;
      
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
class MyCalendarTwo {
public:
    vector<pair<int,int>>allbookings;
    vector<pair<int,int>>overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto &it:overlap){
            if(max(startTime,it.first)<min(endTime,it.second)){
                // triple book
                return 0;   
            }
        }
        for(auto &it:allbookings){
            if(max(startTime,it.first)<min(endTime,it.second)){
                //double book
                overlap.push_back(make_pair(max(startTime,it.first),min(endTime,it.second)));
            }
        }
        allbookings.push_back(make_pair(startTime,endTime));
        return 1;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
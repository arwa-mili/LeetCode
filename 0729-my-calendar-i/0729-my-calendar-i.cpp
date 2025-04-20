class MyCalendar {
public:

  map<int, int> intervals; 
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {

        auto it = intervals.upper_bound(startTime);
        if (it != intervals.begin()) {
              auto prevIt = prev(it);
              if (prevIt->second > startTime) return false;
         }
        if (it != intervals.end() && it->first < endTime) return false;
        intervals[startTime] = endTime;
        return true;

        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
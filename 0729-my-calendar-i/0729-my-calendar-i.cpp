class MyCalendar {
public:
    set<pair<int, int>> intervals;

    MyCalendar() {}

    bool book(int startTime, int endTime) {
        auto it = intervals.lower_bound({startTime, 0});

        if (it != intervals.begin()) {
            auto prevv = prev(it);
            if (prevv->second > startTime) return false;
        }

        if (it != intervals.end() && it->first < endTime) return false;

        intervals.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
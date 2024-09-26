class MyCalendar {
public:
    vector<pair<int,int>> date;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
            
        for(int i = 0 ;i < date.size(); i++) {
            if((date[i].first <= start && date[i].second > start) ||
             (date[i].second > end && date[i].first < end) || 
             (date[i].first >= start && date[i].second <= end)) {
                return false;
            }
        }

        date.push_back({start, end});
        return true;
    }
};

static const int speedup = [](){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
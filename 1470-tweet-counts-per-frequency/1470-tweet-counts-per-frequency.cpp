class TweetCounts {
public:
 //multiset not set because the same tweet can be repeated in the same time
    unordered_map<string, multiset<int>>tweets;
    unordered_map<string, int> scale = {
            {"minute", 60}, 
            {"hour", 3600}, 
            {"day", 86400}
        };
    TweetCounts() {  
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
    }
    
   
     vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> res;
        int interval = scale[freq];

        for (int start = startTime; start <= endTime; start += interval) {
            int end = min(start + interval - 1, endTime);

            auto low = tweets[tweetName].lower_bound(start);
            auto high = tweets[tweetName].upper_bound(end);
            res.push_back(distance(low, high));
        }

        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
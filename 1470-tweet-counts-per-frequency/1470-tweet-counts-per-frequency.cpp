class TweetCounts {
public:

    unordered_map<string, vector<int>>tweets;
    unordered_map<string, int> scale = {
            {"minute", 60}, 
            {"hour", 3600}, 
            {"day", 86400}
        };
    TweetCounts() {  
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector <int>res;
        for (int i=0; i <= (endTime - startTime) / scale[freq]; i++)
            res.push_back(0);

        for (auto& time : tweets[tweetName]) {
            if (time >= startTime && time <= endTime) {
                int index = (time - startTime) / scale[freq];
                res[index]++;
            }
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
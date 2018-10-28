class Twitter {
public:
    struct User {
        vector<pair<int, int>> tweets;
        unordered_set<int> followed;
    };
    unordered_map<int, User> users;
    int clock;
    
    /** Initialize your data structure here. */
    Twitter() {
        clock = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back(make_pair(clock, tweetId));
        ++clock;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    struct Info {
        const vector<pair<int, int>> *tweets;
        int tweetIdx;
    };
    vector<int> getNewsFeed(int userId) {
        if (users.find(userId) == users.end()) {
            return vector<int>();
        }
        map<int, Info, greater<int>> mp;
        const auto &user = users[userId];
        if (!user.tweets.empty()) {
            mp[user.tweets.back().first] = Info{&user.tweets, user.tweets.size()-1};
        }
        for (int id:user.followed) {
            if (!users[id].tweets.empty()) {
                mp[users[id].tweets.back().first] = Info{&(users[id].tweets), users[id].tweets.size()-1};
            }
        }
        
        vector<int> res;
        for (int i=0; i<10 && !mp.empty(); ++i) {
            auto cur = mp.begin();
            auto key = cur->first;
            auto tweets = cur->second.tweets;
            auto tid = cur->second.tweetIdx;
            res.push_back((*tweets)[tid].second);
            if (--tid >= 0) {
                mp[(*tweets)[tid].first] = Info{tweets, tid};
            }
            mp.erase(key);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].followed.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].followed.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
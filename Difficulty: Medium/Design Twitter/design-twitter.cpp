class Twitter {
private:
    // follower -> set of followees
    unordered_map<int, unordered_set<int>> following;

    // user -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;

public:

    Twitter() {
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    // Retrieve 10 most recent tweets
    vector<int> getNewsFeed(int userId) {

        // Make sure user sees his own tweets
        following[userId].insert(userId);

        // max heap:
        // {timestamp, tweetId}
        priority_queue<pair<int, int>> pq;

        // Put all tweets of followed users into heap
        for (auto followee : following[userId]) {

            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        // Take latest 10
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    // Follower follows a followee
    void follow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    // Follower unfollows a followee
    void unfollow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        following[followerId].erase(followeeId);
    }
};
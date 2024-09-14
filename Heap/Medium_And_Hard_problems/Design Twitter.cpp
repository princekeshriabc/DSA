//  Design Twitter
// https://leetcode.com/problems/design-twitter/solutions/5784646/simple-solution-heap-beats-100/

// Time complexity: O(10log(p.size()))
// Space complexity : O(p.size() + 501)

class Twitter
{
    priority_queue<vector<int>> p, temp;
    set<int> following[501];
    int post = 1;

public:
    Twitter()
    {
        for (int i = 0; i < 501; i++)
        {
            following[i].insert(i);
        }
    }

    void postTweet(int userId, int tweetId)
    {
        p.push({post, userId, tweetId});
        post++;
    }

    vector<int> getNewsFeed(int userId)
    {

        temp = p;
        int num = 10;
        vector<int> res;
        while (!temp.empty() && num > 0)
        {
            if (following[userId].find(temp.top()[1]) != following[userId].end())
            {
                num--;
                res.push_back(temp.top()[2]); // get tweetId
            }
            temp.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
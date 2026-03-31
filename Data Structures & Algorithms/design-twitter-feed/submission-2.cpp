
struct Tweet {
  int id;
  int time;
  Tweet(int id, int time) : id(id), time(time) {}
};

struct Person {
  int id;
  vector<Tweet> TweetHistory;
  set<int> followers;
  set<int> following;
  Person() : id(-1) {};
  Person(int id) : id(id) { TweetHistory = {};
  followers = {};
  following = {}; }
};

class Twitter {
public:
  unordered_map<int, Person> Users;
  int time;
  Twitter() : time(0) {}

  void postTweet(int userId, int tweetId) {
    if (Users.find(userId) == Users.end()) {
      Users[userId] = Person(userId);
    }

    Tweet t = Tweet(tweetId, time);
    Users[userId].TweetHistory.push_back(t);
    time++;
  }

  vector<int> getNewsFeed(int userId) {
    vector<Tweet> userFeeds = {};
    if (userExist(userId)) {
      userFeeds.insert(userFeeds.end(), Users[userId].TweetHistory.begin(),
                       Users[userId].TweetHistory.end());
      for (auto user : Users[userId].following) {
        if (userExist(user)) {
          userFeeds.insert(userFeeds.end(), Users[user].TweetHistory.begin(),
                           Users[user].TweetHistory.end());
        }
      }

      auto cmp = []( Tweet t1,  Tweet t2) {
        return t1.time > t2.time;
      };

      priority_queue<Tweet, vector<Tweet>, decltype(cmp)> LatestTweet(cmp);

      for (auto feed : userFeeds) {
        LatestTweet.push(feed);
        if (LatestTweet.size() > 10) {
          LatestTweet.pop();
        }
      }

      vector<int> result;
      while (!LatestTweet.empty()) {
        result.push_back(LatestTweet.top().id);
        LatestTweet.pop();
      }

      reverse(result.begin(), result.end());

      return result;
    }

    return {};
  }

  void follow(int followerId, int followeeId) {
    if(followerId == followeeId) return;
    if (!userExist(followerId)) {
      Users[followerId] = Person(followerId);
    }
    if (!userExist(followeeId)) {
      Users[followeeId] = Person(followeeId);
    }
    Users[followerId].following.insert(followeeId);
    Users[followeeId].followers.insert(followerId);
  }

  void unfollow(int followerId, int followeeId) {
    if(followerId == followeeId) return;
    if (!userExist(followerId)) {
      Users[followerId] = Person(followerId);
    }
    if (!userExist(followeeId)) {
      Users[followeeId] = Person(followeeId);
    }

    if (Users[followerId].following.find(followeeId) !=
        Users[followerId].following.end()) {
      Users[followerId].following.erase(followeeId);
      Users[followeeId].followers.erase(followerId);
    }
  }

  bool userExist(int userID) { return Users.find(userID) != Users.end(); }
};
//
//  twitterFeed.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/25/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "twitterFeed.hpp"
#include <map>
#include <set>
#include <time.h>
#include <iostream>
#include <queue>
#include <unistd.h>

/*
 Twitter twitter = new Twitter();

 // User 1 posts a new tweet (id = 5).
 twitter.postTweet(1, 5);

 // User 1's news feed should return a list with 1 tweet id -> [5].
 twitter.getNewsFeed(1);

 // User 1 follows user 2.
 twitter.follow(1, 2);

 // User 2 posts a new tweet (id = 6).
 twitter.postTweet(2, 6);

 // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 twitter.getNewsFeed(1);

 // User 1 unfollows user 2.
 twitter.unfollow(1, 2);

 // User 1's news feed should return a list with 1 tweet id -> [5],
 // since user 1 is no longer following user 2.
 twitter.getNewsFeed(1);
 */

/*

 Algorithm:

 Data Structures:
   A map of <userid, tweet>
   struct of tweet {tweetid, time}
   A multimap of <userid, followeeid>
   A map of <userid, set<followeeid>>

 Functions:
   postTweet
     - Add pair <id, time> to map vector value
    getNewsFeed
    - for all userid's including self, get top 10 tweets (min heap with time as key)

   follow
    - add to set in a map

   unfollow
    - remove from set

 */

class Twitter {
public:
  map<int, vector< pair<int,uint64_t> > > tweets;
  map<int, set<int> >followee;
  int64_t tweetnum;

  Twitter() {
    tweetnum = 0;
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    pair<int, int64_t> p = make_pair(tweetId, ++tweetnum);
    if(tweets.find(userId) == tweets.end())
    {
      vector< pair<int,uint64_t> > v;
      v.push_back(p);
      tweets[userId] = v;
    }
    else
    {
      tweets[userId].push_back(p);
    }
  }

  struct CustomCompare
  {
    bool operator()(const pair<int,int64_t>& lhs, const pair<int,int64_t>& rhs)
    {
      return lhs.second > rhs.second;
    }
  };

  void insert_priority_queue(
                             priority_queue < pair<int,int64_t>, vector< pair<int,int64_t> >, CustomCompare > *pq, pair<int,int64_t> p)
  {
    if(pq->size() < 10)
    {
      pq->push(p);
    }
    else
    {
      if (p.second > pq->top().second)
      {
        pq->pop();
        pq->push(p);
      }
    }
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> newsFeed;
    map<int, set<int> > :: iterator it = followee.begin();
    priority_queue < pair<int,int64_t>, vector< pair<int,int64_t> >, CustomCompare > pq;

    for(int i=0;i<tweets[userId].size();i++)
    {
      insert_priority_queue(&pq, (tweets[userId])[i]);
    }

    it = followee.find(userId);

    if(it!=followee.end())
    {
      set<int> ::iterator it2 = (it->second).begin();

      for(;it2!=(it->second).end();it2++)
      {
        for(int j=0;j<tweets[*it2].size();j++)
         insert_priority_queue(&pq, (tweets[*it2])[j]);
      }
    }

    while (!pq.empty())
    {
      newsFeed.push_back(pq.top().first);
      pq.pop();
    }

    reverse(newsFeed.begin(),newsFeed.end());
    return newsFeed;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    if(followerId == followeeId)
      return;

    if(followee.find(followerId) == followee.end())
    {
      set<int> s;
      s.insert(followeeId);
      followee[followerId] = s;
    }
    else
    {
      followee[followerId].insert(followeeId);
      cout << followee[followerId].size() << endl;
    }
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if(followee.find(followerId) == followee.end())
    {
      return;
    }
    else
    {
      followee[followerId].erase(followeeId);
    }
  }
};

int main()
{
  Twitter obj;

  vector<int> v;
  obj.postTweet(1,5);
  obj.follow(1,2);
  obj.follow(1,3);
  obj.follow(2,1);
  obj.postTweet(2,6);
  obj.postTweet(3,7);
  v = obj.getNewsFeed(1);
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<"END \n";

}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

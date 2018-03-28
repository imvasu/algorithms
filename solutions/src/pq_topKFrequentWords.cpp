//
//  pq_topKFrequentWords.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/28/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
 input ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 output ["i", "love"]

 */

#include "pq_topKFrequentWords.hpp"
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;


struct compare
{
  bool operator()(const pair<string, int>& l, const pair<string, int>& r)
  {
    int i = l.second;
    int j = r.second;
    if(i == j)
    {
      if((l.first).compare(r.first) > 0)
        return false;
      else
        return true;
    }
    return l.second > r.second;
  }
};



vector<string> topKFrequent(vector<string>& words, int k) {

  map<string, int> wordmap;

  for(int i=0;i<words.size();i++)
  {
    if(wordmap.find(words[i]) == wordmap.end())
    {
      wordmap[words[i]] = 1;
    }
    else
      wordmap[words[i]] = wordmap[words[i]] + 1;
  }

  map<string, int>::iterator it = wordmap.begin();

  priority_queue<pair<string, int>, vector<pair<string, int> >, compare > pq;

  for(;it!=wordmap.end();it++)
  {
      //cout<<it->first << " " <<it->second <<endl;
    pair <string, int> p = make_pair(it->first, it->second);

    if(pq.size() < k)
      pq.push(p);
    else
    {
      pair <string, int> top = pq.top();
      if(top.second < p.second)
      {
        pq.pop();
        pq.push(p);
      }
      else if(top.second == p.second)
      {
        if((top.first).compare(p.first) > 0)
        {
          pq.pop();
          pq.push(p);
        }
      }
    }
  }

  //cout<<pq.size()<<endl;
  vector<string> output;

  while(k!=0)
  {
    if(pq.empty())
      break;
    pair <string, int> p = pq.top();
    output.push_back(p.first);
    pq.pop();

    k--;
  }

  reverse(output.begin(), output.end());

  return output;

}

int main()
{
  const char* str[] = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> words(str, str + sizeof(str)/sizeof(str[0]));

  vector<string> output = topKFrequent(words, 3);

  for(int i=0;i<output.size();i++)
  {
    cout<<output[i]<<" ";
  }

  cout<<endl;

  return 0;
}







//
//  map_groupAnagrams.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/28/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
 INPUT
 anagrams(['xxy', 'cab', 'bca', 'cab', 'bac', 'dash', 'shad'])

 OUTPUT
 [
 ['xxy'],
 ['cab', 'bca’, 'bac'],
 ['dash', 'shad']
 ]

 Group strings that are anagram of each other into a list without duplicate.

 ‘cab’ is an example duplicates removed. There are 2 ‘cab’ in the input and only 1 ‘cab’ in the output.
 You can think of anagram as two words that have the same count per letter. You should treat upper and lower case differently.
 'xxy’ is by itself because it doesn’t have any other strings that are anagram with ’xxy’

 Abc and abc are NOT anagrams
 abcc and abc are NOT anagrams
 abc and cab are anagrams because each of them has 1 a, 1 b, and 1 c

 You can assume it’s 256 ASCII

 You don’t need to compile the code, let me know when you’re done implementing the code. If you’re unsure about the syntax, just make it up.
 */

#include "map_groupAnagrams.hpp"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<set<string> > groupAnagrams(vector<string> input)
{
  map<string, set<string> > groups;

  for(int i=0; i < input.size(); i++)
  {
    string key = input[i];

    sort(key.begin(),key.end());

    if(groups.find(key) == groups.end())
    {
      set<string> s;
      s.insert(input[i]);
      groups[key] = s;
    }
    else
    {
      (groups[key]).insert(input[i]);
    }
  }

  vector<set<string> > output;

  map<string, set<string> > :: iterator it = groups.begin();

  for(;it!=groups.end();it++)
  {
    set<string> values = it->second;

    output.push_back(values);
  }

  return output;
}

int main()
{
  const char* str[] = {"xxy", "cab", "bca", "cab", "bac", "dash", "shad", "shad"};
  vector<string> input(str,str+sizeof(str)/sizeof(str[0]));
  vector<set<string> > output = groupAnagrams(input);

  for(int i=0;i<output.size();i++)
  {
    set<string> :: iterator it = output[i].begin();
    for(;it!=output[i].end();it++)
    {
      cout<<*it<<" ";
    }
    cout<<endl;
  }
}

/*

 ['xxy', 'yxx']

 algorithm:

 {
 ['xxy'] : {'xxy'}
 ['cab'] : {'cab', 'bca’, 'bac'}

 cost of checking for anagram - len(key)
 cost of checking all keys - o(nkeys)

 o(n2)

 keep keys in sorted order

 sort the new key and check in hash whether the key exist or not?

 check and insert anagram - O(klogk)
 }


 input: vector<string> input
 output: vector<vector<string>> output

 1. iterate through the input strings
 2. sort the string
 3. check if it exists in the map
 4. if yes, insert

 Unit tests:
 Test1: 1 string
 Test2: general case
 Test3: all strings are same anagram
 Test4: all unique strings
 Test5: no strings
 */

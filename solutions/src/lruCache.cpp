//
//  lruCache.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/28/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
 The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

 Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor.
 Example :

 Input :
 capacity = 2
 set(1, 10)
 set(5, 12)
 get(5)        returns 12
 get(1)        returns 10
 get(10)       returns -1
 set(6, 14)    this pushes out key = 5 as LRU is full.
 get(5)        returns -1

 input: 7 2 S 2 1 S 1 1 S 2 3 G 2 S 4 1 G 1 G 2


 Algorithm:
   doubly linked list with a map
   map <key, node>

 get:
  find key
  move the key to the front of the list

 set:
  find key
  move the key to the front of the list
  remove lru key from list and from cache

 */


#include "lruCache.hpp"
#include <iostream>
#include <list>
#include <map>

using namespace std;

int capacity = 0;

list<pair<int, int> > node;
map<int, list<pair<int, int> >::iterator>cache;

void set_key(int key, int value)
{
  if(cache.find(key) != cache.end())
  {
    node.erase(cache[key]);
  }
  else if(node.size() == capacity)
  {
    pair<int, int> p = (node.back());
    int k = p.first;
    node.erase(cache[k]);
    cache.erase(k);
  }
  pair<int, int> p(key, value);
  node.push_front(p);
  cache[key] = node.begin();
}

int get_key(int key)
{
  if(cache.find(key) == cache.end())
  {
    return -1;
  }
  pair <int, int> p = *(cache[key]);
  int val = p.second;
  node.erase(cache[key]);
  node.push_front(p);
  cache[key] = node.begin();
  return val;
}

int main()
{
  int numOps;
  cin >> numOps;
  cin >> capacity;
  char op;
  int key;
  int value;

  cout << numOps << endl;
  cout << capacity << endl;

  for (int i=0; i< numOps; i++)
  {
    cin >> op;
    if(op == 'S')
    {
      cin >> key;
      cin >> value;
      set_key(key,value);
    }
    else
    {
      cin >> key;
      cout<<get_key(key)<<endl;
    }
  }
}


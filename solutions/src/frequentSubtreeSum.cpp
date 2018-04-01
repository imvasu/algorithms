//
//  frequentSubtreeSum.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/31/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

5
/  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

5
/  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

*/

#include "frequentSubtreeSum.hpp"
#include <map>
#include <vector>
#include <iostream>

using namespace std;


/*

 1. compute sum at each node
 a. do depth first for each node, track the sum;
 b. at each node, add sum of left subtree and right subtree

 2. keep map of <sum, count>
 a. iterate through the map and find max count
 b. map <count, sum>
 3. return top value
 4.
 */

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


map<int, int> sum_map;

int findSubtreeSum(TreeNode* root)
{
  if(root==NULL)
    return 0;

  int lhs = findSubtreeSum(root->left);
  int rhs = findSubtreeSum(root->right);

  int sum = lhs + rhs + root->val;
  if(sum_map.find(sum) == sum_map.end())
  {
    sum_map[sum] = 1;
  }
  else
    sum_map[sum] = sum_map[sum] + 1;

  return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {

  findSubtreeSum(root);

  map<int, vector<int> > count_map;
  map<int, int> :: iterator it;

  for(it = sum_map.begin();it!=sum_map.end();it++)
  {
      //cout << it->first << " " <<it->second<<endl;

    int count = it->second;
    if(count_map.find(count) == count_map.end())
    {
      vector<int> v;
      v.push_back(it->first);
      count_map[count] = v;
    }
    else
    {
      (count_map[count]).push_back(it->first);
    }
  }

  vector<int> result;

  if(count_map.size() > 0)
  {
    map<int, vector<int> > :: iterator it2 = count_map.end();
    --it2;
    result = it2->second;
  }

  return result;
}

TreeNode* createTree(int arr[])
{
  TreeNode* root = NULL;
  root = new TreeNode(arr[0]);
  TreeNode *left = new TreeNode(arr[1]);
  TreeNode *right = new TreeNode(arr[2]);
  root->left = left;
  root->right = right;

  return root;
}

int main()
{
  int arr[] = {5,2,-5};
  TreeNode* root = createTree(arr);

  vector<int> result = findFrequentTreeSum(root);
  for(int i=0; i < result.size(); i++)
  {
    cout << result[i]<<" ";
  }
  cout<<endl;

  return 0;
}


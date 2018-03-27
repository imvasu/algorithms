//
//  tree_salesPath.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/27/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "tree_salesPath.hpp"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Node
{
  int cost;
  vector<Node *> children;
  Node *parent;
};

int getCheapestCost( Node *rootNode )
{
    // your code goes here
  if(rootNode == NULL)
  {
    return -1;
  }

  if((rootNode->children).size() == 0)
    return rootNode->cost;

  int rootCost = rootNode->cost;

  int minChildCost = INT_MAX;

  for(int i=0; i<(rootNode->children).size();i++)
  {
    int cost = getCheapestCost((rootNode->children)[i]);

    if(minChildCost > cost)
      minChildCost = cost;
  }

  return minChildCost+rootCost;

}


Node * newNode(int cost)
{
  struct Node *root = (struct Node*)calloc(1, sizeof(struct Node));
  root->cost = cost;
  return root;
}

Node *addChild(struct Node *root, int cost)
{
  struct Node *child = newNode(cost);
  child->parent = root;
  (root->children).push_back(child);

  return child;
}


Node * createTestTree()
{
  struct Node *root = newNode(0);
  struct Node *child1 = addChild(root, 5);
  struct Node *child2 = addChild(root, 3);
  struct Node *child3 = addChild(root, 7);

  return root;
}



int main() {

  struct Node *root = createTestTree();
  int minCost = getCheapestCost(root);

  cout<<"Min Cost: "<<minCost<<endl;

  return 0;
}

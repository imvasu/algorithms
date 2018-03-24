/*
 * Copyright (c) 2018 Algorithms LLC and its affiliates
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include <stdlib.h>
#include "BST_findLargestSmallerKey.hpp"

#include <iostream>

using namespace std;


// Helper function that allocates a new Node
Node* newNode( int key )
{
  Node* n = new Node;
  n->key = key;
  n->left = nullptr;
  n->right = nullptr;
  n->parent = nullptr;

  return n;
}

  //  Given a binary search tree and a number, inserts a new Node with
  //  the given number in the correct place in the tree. Returns the new
  //  root pointer which the caller should then use
Node *insert( Node *root, int key )
{
    // 1) If the tree is empty, return a new single Node
  if( root == nullptr )
    return newNode( key );

  Node *temp;

    // 2) Otherwise, recur down the tree
  if( key < root->key )
  {
    temp = insert( root->left, key );
    root->left = temp;
    temp->parent = root;
  } else
  {
    temp = insert( root->right, key );
    root->right = temp;
    temp->parent = root;
  }

    // Return the (unchanged) Node pointer
  return root;
}

int checkForLargestSmallerKey(int key1, int key2, int num)
{
  if(key1 >= num && key2 >= num)
  {
    return -1;
  }

  if(key1 >= num && key2 <= num)
  {
    return key2;
  }

  if(key1 <= num && key2 >= num)
  {
    return key1;
  }

  if(key1 <= key2)
  {
    return key2;
  }
  else
  {
    return key1;
  }

}

int findLargestSmallerKey(Node *rootNode, int num)
{
  if(rootNode == nullptr)
  {
    return -1;
  }

  int result = -1;

  if(rootNode->key >= num)
  {
    result = findLargestSmallerKey(rootNode->left, num);
  }
  else if (rootNode->key < num)
  {
    result = findLargestSmallerKey(rootNode->right, num);
  }

  result = checkForLargestSmallerKey(rootNode->key, result, num);

  return result;

}

/*
int main() {
  Node *root = nullptr;

  const int keys[7] = {20, 15, 25, 16, 12, 11, 10};

  for(int i = 0; i< sizeof(keys)/sizeof(int); i++)
  {
    root = insert(root, keys[i]);
  }

  int result = findLargestSmallerKey(root, 17);

  printf("%d %d %d %d\n", root->key, root->left->key, root->right->key, result);

  return 0;
}
 */



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

#ifndef _BST_findLargestSmallerKey_HPP
#define _BST_findLargestSmallerKey_HPP

#include <string>
#include <map>
#include <list>

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

Node *insert( Node *root, int key );

int findLargestSmallerKey(Node *rootNode, int num);

#endif // _BST_findLargestSmallerKey_HPP

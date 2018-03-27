//
//  reverse_linkedList.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/27/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "reverse_linkedList.hpp"
#include <iostream>

using namespace std;

struct Node
{
  int val;
  Node *next;
};

typedef struct Node Node;

Node * createLinkedList()
{
  Node *root = (Node *)calloc(1, sizeof(Node));
  root->val = 1;
  root-> next = NULL;

  Node *iter = root;
  for(int i=2; i< 10;i++)
  {
    iter->next = (Node*)calloc(1, sizeof(Node));
    (iter->next)->val = i;
    iter = iter->next;
  }
  return root;
}

void printLinkedList(Node *root)
{
  while(root!=NULL)
  {
    cout << root->val <<" ";
    root = root->next;
  }

  cout<<endl;
}

/*
  1
  1->2->3
 {1<-2<-3

  temp = reverseLinkedList(root->next)
  (root->next)->next = root;
  root->next = NULL;

   return temp;


 */


Node * reverseLinkedList(Node *root)
{
  if(root == NULL)
    return NULL;

  if(root->next == NULL)
    return root;


  Node *temp = reverseLinkedList(root->next);
  (root->next)->next = root;
  root->next = NULL;

  return temp;
}



int main()
{
  Node *root = createLinkedList();
  printLinkedList(root);
  root = reverseLinkedList(root);
  printLinkedList(root);
}


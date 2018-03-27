//
//  reverse_kNodeLinkedList.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/27/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "reverse_kNodeLinkedList.hpp"
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

 1->2->3->4->5->6->7->8->9
 2->1->4->3->6->5->8->7->9

 //get prev, get succ;
  reverseLists(begin, k)
  //get new root and new tail

  prev->next = new root
  tail->next = succ
  2->1->3->4
  2->1->4->3->5->6

 */


Node * reverseLinkedList(Node *root, int k)
{
  k--;
  if(root == NULL)
    return NULL;

  if(root->next == NULL)
    return root;

  if(k==0)
    return root;

  Node *temp = reverseLinkedList(root->next, k);
  (root->next)->next = root;
  root->next = NULL;

  return temp;
}

Node * getSucc(Node *root, int k)
{
  while(root!=NULL && k!=0)
  {
    root = root->next;
    k--;
  }

  return root;
}

Node * getTail(Node *root)
{
  if(root == NULL)
    return NULL;

  while(root->next!=NULL)
  {
    root = root->next;
  }

  return root;
}

Node *reverseKNodeLinkedlist(Node *root, int k)
{

  Node *prev = NULL;
  Node *succ = NULL;
  Node *iter = root;
  Node *result = NULL;

  while(iter!=NULL)
  {
    succ = getSucc(iter, k);
    Node * new_root = reverseLinkedList(iter, k);
    Node * new_tail = getTail(new_root);

    if(result == NULL)
      result = new_root;

    if(prev!=NULL)
      prev->next = new_root;

    new_tail->next = succ;
    prev = new_tail;
    iter = succ;
  }

  return result;

}


int main()
{
  Node *root = createLinkedList();
  printLinkedList(root);
  root = reverseKNodeLinkedlist(root,5);
  printLinkedList(root);
}


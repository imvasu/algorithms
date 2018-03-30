//
//  dp_coinChange.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/30/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "dp_coinChange.hpp"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map <int, int> mem;

//top down
/*
 {1,2}
 F[5] = F[4], F[3]
 F[4] = F[3], F[2]
 F[3] = 1, F[1]
 F[2] = F[1], F[0]
 F[1] = 1

 [186,419,83,408]
 6249
 F[6249] = F[6249-186]
 */

int coinChangeT(vector<int>& coins, int amount)
{
  if(amount == 0)
    return 0;

  if(amount < 0)
    return -1;

  if(mem.find(amount) != mem.end())
    return mem[amount];

  int min = INT_MAX;

   cout<<amount<<endl;

  for(int i=0;i<coins.size();i++)
  {
    int n = coinChangeT(coins, amount-coins[i]);

    if(n >= 0)
    {
      if (min > (n))
        min = 1+n;
    }
    else
    {

    }
  }

  if(min != INT_MAX)
  {
    mem[amount] = min;
    return min;
  }
  else
  {
    mem[amount] = -1;
    return -1;
  }
}

/*
 bottom up
 {1,2, 3}
 F(0) = 0 //basecase
 F(1) = min(F(0)) +1
 F(2) = min(F(1), F(0)) + 1
 F(3) = min(F(2), F(1), F(0)) + 1
 */
int coinChange(vector<int>& coins, int amount) {

  if(amount <= 0)
    return 0;

  int ncoins[amount+1];
  memset(&ncoins, -1, sizeof(ncoins));
  ncoins[0] = 0;

  for(int i=1; i<=amount;i++)
  {
    int min = INT_MAX;
    for(int j=0;j<coins.size();j++)
    {
      if((i-coins[j]) >= 0 && ncoins[i-coins[j]] != -1)
      {
        if(min > 1+ncoins[i-coins[j]])
          min = 1+ncoins[i-coins[j]];
      }
    }
    if(min != INT_MAX)
      ncoins[i] = min;
    else
      ncoins[i] = -1;
  }

  return ncoins[amount];
}

int main()
{
  int c[] = {186,419,83,408};
  int amount = 6249;
  vector<int>coins(c,c+sizeof(c)/sizeof(c[0]));
  cout << coinChange(coins, amount) << endl;
  cout << coinChangeT(coins, amount) << endl;
}


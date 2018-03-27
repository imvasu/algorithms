//
//  pairSum.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/26/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "pairSum.hpp"

/*

 put all the numbers in an unordered map or a map
 for each number, check if the number is available, if yes decrease the count
 add the pair to the result
 */

multimap<int, int> findPairSum(vector<int> num, int sum)
{

  map <int, int> numCount;
  map <int, int> iter;
  multimap <int, int> result;

  //populate numCount
  for(int i=0; i<num.size();i++)
  {

    if(numCount.find(num[i]) == numCount.end())
    {
      numCount[num[i]] = 1;
    }
    else
    {
      numCount[num[i]] = numCount[num[i]] + 1;
    }
  }

  for(int i=0; i<num.size();i++)
  {
    if(numCount.find(num[i]) != numCount.end() && numCount.find(sum-num[i]) != numCount.end())
    {
      result.insert(pair<int, int>(num[i], sum-num[i]));

      if(numCount[num[i]] == 1)
      {
        numCount.erase(num[i]);
      }
      else
      {
        numCount[num[i]]  = numCount[num[i]]  - 1;
      }

      if(numCount[sum-num[i]] == 1)
      {
        numCount.erase(sum-num[i]);
      }
      else
      {
        numCount[sum-num[i]]  = numCount[sum-num[i]]  - 1;
      }
    }
  }

  return result;

}

int main()
{
  int arr[] = {1,2,3,2,4,2,2};
  vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));

  multimap<int, int> result = findPairSum(input, 4);

  for(multimap<int, int> :: iterator it = result.begin(); it != result.end();it++)
  {
    cout<< it->first << " " << it->second << endl;
  }
}

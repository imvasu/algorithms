//
//  Array_maxContiguousSum.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/21/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "Array_getMaxContiguousSum.hpp"


int getMaxContiguousSum(int *arr, int nelements)
{
  if((arr == NULL) || (nelements <=0))
  {
    return -1;
  }

  int sum = arr[0];
  int max = arr[0];

  for (int i=1; i<nelements; i++) {

    if(arr[i] > arr[i]+sum)
    {
      sum = arr[i];
    }
    else
    {
      sum = arr[i] + sum;
    }

    if(max < sum)
    {
      max = sum;
    }

  }
  return max;
}

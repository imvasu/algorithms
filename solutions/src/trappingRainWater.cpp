//
//  trappingRainWater.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/30/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include "trappingRainWater.hpp"
#include <vector>
#include <iostream>

using namespace std;

int trap(vector<int>& height) {
    //max height at each index from the back
    //at each index, check max height
    //trap water equal to current height until next height is hit
    //update next height as current height
  vector <int> nextheight;
  int max = 0;

  for(int i=height.size()-1; i>=0;i--)
  {
    nextheight.push_back(max);
    if(max < height[i])
      max = height[i];
  }
  reverse(nextheight.begin(), nextheight.end());

  /* Debug
  for(int i=0;i < nextheight.size() ;i++)
    cout <<nextheight[i]<<" ";

  cout<<endl;
   */

  int currheight = 0;
  int watertapped = 0;
  for(int i=0;i<height.size();i++)
  {

    if(height[i]<currheight)
    {
      watertapped = watertapped + currheight - height[i];
    }

    if(height[i] > currheight)
    {
      currheight = height[i];
    }

    if(currheight > nextheight[i])
      currheight = nextheight[i];

  }

  return watertapped;
}

int main()
{
  const int input[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int>height(input, input+sizeof(input)/sizeof(input[0]));
  cout<<trap(height)<<endl;
}

//
//  matrix_imageSmoother.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/27/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
 Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

 Example 1:
 Input:
 [[1,1,1],
 [1,0,1],
 [1,1,1]]
 Output:
 [[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
 Explanation:
 For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 For the point (1,1): floor(8/9) = floor(0.88888889) = 0

 */

#include "matrix_imageSmoother.hpp"

bool get(int r, int c, int rnum, int cnum)
{
  if(r<0 || r>=rnum)
    return false;

  if(c<0 || c>=cnum)
    return false;

  return true;
}

vector<vector<int> > imageSmoother(vector<vector<int> >& M) {

  vector<vector<int> > output;
  for(int i=0;i<M.size();i++)
  {
    vector<int> row;
    for(int j=0; j< M[i].size();j++)
    {
      int value = 0;
      int count = 0;

      for(int row=i-1;row<=i+1;row++)
        for(int column = j-1; column<=j+1;column++)
        {
          if(get(row, column, M.size(), M[i].size()))
          {
            value = value + M[row][column];
            count = count + 1;
          }
        }

        //cout << i << j << value << count << endl;
      row.push_back(floor(value/count));
    }
    output.push_back(row);
  }

  return output;

}

int main()
{
  int myints[3][3] = {{1,2,1},{1,0,1},{1,1,1}};

  vector<vector<int> > input;
  input.push_back(vector<int>(myints[0],myints[0]+3));
  input.push_back(vector<int>(myints[1],myints[1]+3));
  input.push_back(vector<int>(myints[2],myints[2]+3));

  vector<vector<int> > output = imageSmoother(input);
  for(int i=0;i<output.size();i++)
  {
    for(int j=0; j< output[i].size();j++)
      cout<<output[i][j]<<" ";

    cout<<endl;
  }
}

//
//  greyCode.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/26/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

/*
 XOR from binary to grey code
 https://testbook.com/blog/conversion-from-gray-code-to-binary-code-and-vice-versa/

 Recursion:
*/

#include "greyCode.hpp"

/*
 Data Structures:
 vector <int> result;
 vector <string> greycode_str;

 Base:
 n =0
 return 0;

 n = 1
 return 0, 1

  n = 2
  getGreyCode(n-1)
  append 0 for half and 1 for other half
  convert back to int and send result oit
 */

//print grey code for n bits decimal numbers (0-2^n)
vector<int> getGreyCode(int n)
{
  vector<int> result;

  if(n==0)
  {
    result.push_back(0);
    return result;
  }

  if(n==1)
  {
    result.push_back(0);
    result.push_back(1);
    return result;
  }

  result = getGreyCode(n-1);

  int totalNum = 1<<n;
  int bit = 0;

  for(size_t i=result.size();i>0;i--)
  {
    result.push_back(result[i-1]);
  }

  for(int i=0;i<totalNum;i++)
  {
    if(i>=(totalNum/2))
    {
      bit = 1;
    }

    result[i] = result[i] | (bit<<(n-1));
  }

  return result;

}

//{0,1,1,0}

int main()
{
  vector<int> result = getGreyCode(3);
  for(int i=0; i<result.size();i++)
  {
    cout<<result[i]<<endl;
  }
}

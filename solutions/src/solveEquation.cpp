//
//  solveEquation.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/27/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "solveEquation.hpp"

pair <int, int> getcount(string s)
{
    //cout<<s<<endl;
  int xval = 0;
  int cval = 0;
  int sign = 1;
  int val = 0;

  for(int i=0;i<s.length();i++)
  {
    if(s[i] == 'x')
    {
      if(i > 0 && (s[i-1] != '+' && s[i-1] !='-')) {
        xval = xval + sign*val;
        val = 0;
      }
      else {
        xval = xval + sign;
      }
    }
    else if((s[i] == '+') || (s[i] == '-'))
    {
      cval = cval + sign*val;
      val = 0;
      s[i]=='+'?sign=1:sign=-1;
    }
    else {
        //cout<<s[i]<<" "<<val<<endl;
      char c = s[i];
      val = val*10 + atoi(&c);
        //cout<<"val"<<val<<endl;
    }
  }

  if(val != 0)
    cval = cval + sign*val;

    //cout<<xval <<" "<<cval<<endl;
  pair <int,int> p = make_pair(xval, cval);
  return p;
}

string solveEquation(string equation) {
  std::size_t pos = equation.find("=");

  if (pos==std::string::npos)
  {
    return "No solution";
  }

  string lhs =  equation.substr (0,pos);
  string rhs = equation.substr(pos+1);

  pair <int, int> l = getcount(lhs);
  pair <int, int> r = getcount(rhs);

  int xcount = (l.first-r.first);
  int coeff = l.second-r.second;

  if(xcount == 0 && coeff == 0)
    return "Infinite solutions";

  if(xcount == 0)
    return "No solution";

  string result = "x";
  int sign = 1;


  if(xcount>0)
  {
    sign = -1;
  }

  result = result + "=" + to_string((sign)*coeff/abs(xcount));

  return result;
}

int main()
{
  string input = "x+5-3+x=6+x-2";
  string result = solveEquation(input);

  cout<<result<<endl;
}


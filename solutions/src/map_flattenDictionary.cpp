//
//  map_flattenDictionary.cpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/23/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#include "map_flattenDictionary.hpp"
#include <iostream>
#include <unordered_map>

void flattenDictionaryHelper(string key, value v, map<string, string> *out)
{
   if(v.data_type == DATA_PRIMITIVE)
   {
     string data_str = (char*)v.data;
     (*out)[key] = data_str;
   }
  else
  {
    map<string, value> *v1 = (map<string, value> *)v.data;
    map<string, value>::iterator it = (*v1).begin();
    for(;it!=(*v1).end();it++)
    {
      string new_key = it->first;
      value v2 = (value)it->second;
      flattenDictionaryHelper(key+"."+new_key, v2, out);
    }
  }
}

map<string, string>* flattenDictionary(map<string, value> *dict)
{
  map<string, value>::iterator it = (*dict).begin();
  map<string, string> *out = new map<string, string>();

  for(it=(*dict).begin(); it!=(*dict).end();it++)
  {
    string key = it->first;
    flattenDictionaryHelper(key,(value)it->second,out);
  }

  return (out);
}

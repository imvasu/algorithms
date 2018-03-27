//
//  map_flattenDictionary.hpp
//  algorithms
//
//  Created by Vasu Pasupuleti on 3/23/18.
//  Copyright © 2018 Vasu Pasupuleti. All rights reserved.
//

#ifndef map_flattenDictionary_hpp
#define map_flattenDictionary_hpp

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

typedef enum
{
  DATA_PRIMITIVE,
  DATA_MAP
} data_types_t;


typedef struct{
  data_types_t data_type;
  void* data;
}value;

map<string, string>* flattenDictionary(map<string, value> *dict);

#endif /* map_flattenDictionary_hpp */

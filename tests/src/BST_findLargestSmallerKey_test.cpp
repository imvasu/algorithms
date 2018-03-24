/*
 * Copyright (c) 2018 Algorithms LLC and its affiliates
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cgreen/cgreen.h>
#include <BST_findLargestSmallerKey.hpp>
#include <Array_getMaxContiguousSum.hpp>
#include <map_flattenDictionary.hpp>
#include <iostream>

using namespace cgreen;

Describe(BST_findLargestSmallerKey);
BeforeEach(BST_findLargestSmallerKey) { }
AfterEach(BST_findLargestSmallerKey) { }

/**
 * @brief Unit Test for Valid Full Config
 */
Ensure(BST_findLargestSmallerKey, test_BST_findLargestSmallerKey)
{
  Node *root = nullptr;

  const int keys[7] = {20, 15, 25, 16, 12, 11, 10};

  for(int i = 0; i< sizeof(keys)/sizeof(int); i++)
  {
    root = insert(root, keys[i]);
  }

  int result = findLargestSmallerKey(root, 7);

  assert_that(result, is_equal_to(-1));
}

/**
 * @brief Unit Test for Valid Full Config
 */
Ensure(BST_findLargestSmallerKey, test_Array_getMaxContiguousSum)
{
  int arr[7] = {3,2,-7,1,2,-4,2};

  int result = getMaxContiguousSum(arr, 7);

  assert_that(result, is_equal_to(5));
}

/**
 * @brief Unit Test for Valid Full Config
 */
Ensure(BST_findLargestSmallerKey, test_map_flattenDictionary)
{
  //create dictionary
  map<string, value> *dict = new map<string, value>() ;
  
  value v;
  v.data_type = DATA_PRIMITIVE;
  v.data = (void*)"1";
  (*dict)["key1"] = v;

  map<string, value> *child_dict = new map<string, value>();
  v.data = (void*)"2";
  (*child_dict)["a"] = v;
  v.data = (void*)"3";
  (*child_dict)["b"] = v;

  map<string, value> *child_dict_2 = new map<string, value>();
  v.data = (void*)"4";
  (*child_dict_2)["d"] = v;

  v.data_type = DATA_MAP;
  v.data = (void*)child_dict_2;
  (*child_dict)["c"] = v;

  v.data_type = DATA_MAP;
  v.data = (void*)child_dict;
  (*dict)["key2"] = v;

  map<string, string> *out = flattenDictionary(dict);

  const char* output[] = {"key1:1",
                          "key2.a:2",
                          "key2.b:3",
                          "key2.c.d:4"};

  int idx = 0;
  for(map<string, string>::iterator it = (*out).begin();it!=(*out).end();it++)
  {
    string out = it->first + ":" + it->second;
    assert_that(strcmp(output[idx++], out.c_str()), is_equal_to(0));
  }

  //add test cases for empty keys to be ignored
}

TestSuite* BST_findLargestSmallerKey_tests()
{

  TestSuite* suite = create_test_suite();

  add_test_with_context(suite, BST_findLargestSmallerKey, test_BST_findLargestSmallerKey);
  add_test_with_context(suite, BST_findLargestSmallerKey, test_Array_getMaxContiguousSum);
  add_test_with_context(suite, BST_findLargestSmallerKey, test_map_flattenDictionary);

  return suite;
}

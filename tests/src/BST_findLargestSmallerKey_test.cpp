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

using namespace cgreen;

Describe(BST_findLargestSmallerKey);
BeforeEach(BST_findLargestSmallerKey) { }
AfterEach(BST_findLargestSmallerKey) { }

/**
 * @brief Unit Test for Valid Full Config
 */
Ensure(BST_findLargestSmallerKey, returns_success_on_valid_result)
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

TestSuite* BST_findLargestSmallerKey_tests()
{

  TestSuite* suite = create_test_suite();

  add_test_with_context(suite, BST_findLargestSmallerKey, returns_success_on_valid_result);

  return suite;
}

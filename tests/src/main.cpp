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

#include <iostream>
#include <cgreen/cgreen.h>


using namespace cgreen;

//Declare all the tests
TestSuite* BST_findLargestSmallerKey_tests();

/**
 * @brief create a test suite and run the tests
 */
int main(int argc, const char* argv[])
{
  TestSuite* suite = create_test_suite();

  add_suite(suite, BST_findLargestSmallerKey_tests());
 
  if (argc > 1)
  {
    return run_single_test(suite, argv[1], create_text_reporter());
  }

  return run_test_suite(suite, create_text_reporter());
}

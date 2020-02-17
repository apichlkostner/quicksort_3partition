#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include "../src/sorting.h"
#include "test_helpers.h"

#include "gtest/gtest.h"

TEST(quicksort, small) {
  std::vector<int> values = {1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, tiny) {
  std::vector<int> values = {1, 2};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, tiny2) {
  std::vector<int> values = {2, 1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, tiny3) {
  std::vector<int> values = {1, 2, 1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, tiny4) {
  std::vector<int> values = {2, 1, 2};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, allequal) {
  std::vector<int> values = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, increasing) {
  std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, decreasing) {
  std::vector<int> values = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, highlow) {
  std::vector<int> values = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, lowhigh) {
  std::vector<int> values = {5, 4, 3, 2, 1, 2, 3, 4, 5};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, alternating) {
  std::vector<int> values = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, alternating2) {
  std::vector<int> values = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}

TEST(quicksort, alternating3) {
  std::vector<int> values = {1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 2};
  quicksort(values);
  ASSERT_TRUE(is_sorted(values));
}


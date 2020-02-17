#include "test_helpers.h"
#include "gtest/gtest.h"

// tests the test helper function is_sorted
TEST(test_helpers, is_sorted_allequal) {
    std::vector<int> values = {1,1,1,1,1,1,1,1};
    ASSERT_TRUE(is_sorted(values));
}

TEST(test_helpers, is_sorted_increasing) {
    std::vector<int> values = {1,2,3,4,5,6,7,8};
    ASSERT_TRUE(is_sorted(values));
}

TEST(test_helpers, is_sorted_increasing_equal) {
    std::vector<int> values = {1,2,2,4,5,5,7,8};
    ASSERT_TRUE(is_sorted(values));
}

TEST(test_helpers, is_sorted_false_middle) {
    std::vector<int> values = {1,2,1,4,5,6,7,8};
    ASSERT_FALSE(is_sorted(values));
}

TEST(test_helpers, is_sorted_false_end) {
    std::vector<int> values = {1,2,3,4,5,6,7,6};
    ASSERT_FALSE(is_sorted(values));
}

TEST(test_helpers, is_sorted_false_begin) {
    std::vector<int> values = {3,2,3,4,5,6,7,6};
    ASSERT_FALSE(is_sorted(values));
}
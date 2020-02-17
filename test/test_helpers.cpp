#include "test_helpers.h"
#include "gtest/gtest.h"

// Checks if the vector values is sorted
bool is_sorted(std::vector<int>& values) {
  // check if vector is sorted
  int v_old = values[0];
  for (auto& v : values) {
    if (v < v_old) return false;
    v_old = v;
  }

  return true;
}
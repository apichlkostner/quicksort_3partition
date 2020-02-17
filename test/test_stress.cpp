#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include "../src/sorting.h"
#include "test_helpers.h"

#include "gtest/gtest.h"

static void stress_test_sorting(int random_init);

TEST(quicksort, stresstest) {
#if MULTITHREADED
  const auto NUMTHREADS = std::thread::hardware_concurrency();

  std::vector<std::thread> calcthreads;

  for (size_t i = 0; i < NUMTHREADS; i++)
    calcthreads.push_back(std::thread(stress_test_sorting, i));
  for (auto& t : calcthreads) t.join();
#else
  stress_test_sorting(1);
#endif
}



static void stress_test_sorting(int random_init) {
  constexpr size_t NUM_TESTS = 10000;
  constexpr size_t MAX_N = 1000;
  constexpr int MAX_VAL = 10;

  // random number generator
  std::mt19937 gen(random_init);
  std::uniform_int_distribution<uint64_t> distribution_n(1, MAX_N);
  auto randnumvals = std::bind(distribution_n, gen);
  std::uniform_int_distribution<int> distribution_values(1, MAX_VAL);
  auto randvalues = std::bind(distribution_values, gen);

  // run NUM_TESTS random tests
  std::vector<int> values;
  for (size_t i = 0; i < NUM_TESTS; i++) {
    // generate vector with random size and random values
    size_t n = randnumvals();
    values.resize(n);

    for (size_t i = 0; i < n; i++) {
      values[i] = randvalues();
    }

    // sort vector
    quicksort(values);

    // check if vector is sorted
    is_sorted(values);
  }
}
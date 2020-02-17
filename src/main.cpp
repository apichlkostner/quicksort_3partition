
#include <iostream>
#include "sorting.h"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quicksort(a);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
#include <cstdlib>
#include <vector>

// makes three partitions: smaller, equal, greater pivot element
template <class comparable>
static std::pair<int, int> partition3(std::vector<comparable> &a, int l, int r) {
  int x = a[l];
  int boundary_pos = l;
  int pivots_pos = 0;

  for (int pos = l + 1; pos <= r; pos++) {
    if (a[pos] < x) {
      // element is smaller than the pivot, put it to the left partition
      boundary_pos++;
      std::swap(a[pos], a[boundary_pos]);
    }
    if (a[pos] == x) {
      // same like pivot, copy to the left
      pivots_pos++;
      boundary_pos++;
      std::swap(a[pos], a[l + pivots_pos]);
      // put swapped element to it's correct partition
      if (a[pos] < x) {
        std::swap(a[pos], a[boundary_pos]);
      }
    }
  }

  // copy pivot elements to it's final position
  for (int pos = 0; pos <= pivots_pos; pos++) {
    std::swap(a[l + pos], a[boundary_pos - pos]);
  }

  // return left and right boundary of the pivot elements
  return {boundary_pos - pivots_pos, boundary_pos};
}

// recursive implementation of the randomized quicksort algorithm
template <class comparable>
static void randomized_quick_sort(std::vector<comparable> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  std::swap(a[l], a[k]);
  auto m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

// quicksort of vector a
template <class comparable>
void quicksort(std::vector<comparable> &a) {
  randomized_quick_sort(a, 0, a.size() - 1);
}

// declare an instance for int
template void quicksort<int>(std::vector<int> &a);
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int>::const_pointer BinarySearchHelper(vector<int>::const_iterator begin,
                                              vector<int>::const_iterator end,
                                              int elem) {  // NOLINT
  if ((end - begin) < 1) {
    return nullptr;
  } else if ((end - begin) == 1) {
    if (*begin == elem) {
      return vector<int>::const_pointer{begin.base()};
    } else {
      return nullptr;
    }
  }
  auto midpoint = (end - begin) / 2;
  // check
  if (*(begin + midpoint) == elem) {
    return vector<int>::const_pointer{(begin + midpoint).base()};
  } else if (*(begin + midpoint) > elem) {
    cout << "Going to: ";
    for_each(begin, begin + midpoint, [](int elem) { cout << elem << ", "; });
    cout << endl;
    return BinarySearchHelper(begin, begin + midpoint, elem);
  } else {
    cout << "Going to: ";
    for_each(begin + midpoint, end, [](int elem) { cout << elem << ", "; });
    cout << endl;
    return BinarySearchHelper(begin + midpoint, end, elem);
  }
}

vector<int>::const_pointer BinarySearch(const vector<int>* vec_p, int elem) {
  vector<int> vec(vec_p->begin(), vec_p->end());

  sort(vec.begin(), vec.end());

  return BinarySearchHelper(vec.begin(), vec.end(), elem);
}

int main() {
  vector<int> vec{3, 3, 4, 5, 6, 6, 53, 7, 12, 8, 9, 12, 4, 5, 6};
  auto p = BinarySearch(&vec, 12);
  cout << "IsNull: " << (p == nullptr) << endl << "Found: " << *p << endl;
}
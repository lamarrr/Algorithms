#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(vector<int>* vec_p) {
  auto& vec = *vec_p;
  vector<int> tmp;

  while (!vec.empty()) {
    auto elem_pos = std::min_element(vec.begin(), vec.end());

    tmp.push_back(*elem_pos);
    vec.erase(elem_pos);
  }

  vec = std::move(tmp);
}

int main() {
  vector<int> pp{5, 25, 3, 4, 5, 6, 2, 4, 5, 6};
  cout << "Before sort: ";
  for_each(pp.begin(), pp.end(), [](int elem) { cout << elem << ", "; });
  SelectionSort(&pp);
  cout << "\nAfter sort: ";
  for_each(pp.begin(), pp.end(), [](int elem) { cout << elem << ", "; });
  cout << endl;
}
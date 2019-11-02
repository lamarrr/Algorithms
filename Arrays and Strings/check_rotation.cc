#include <iostream>
#include <string>
#include <string_view>

using namespace std;

bool IsRotation(string_view a, string_view b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); i++) {
    if (a.rbegin()[i] != b[i]) return false;
  }
  return true;
}

int main() {
  string a{"hello"};
  string b{"yo"};
  string c{"olleh"};

  cout << boolalpha << IsRotation(a, b) << ", " << IsRotation(a, c) << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream input("input.txt");

  string line;
  int sum = 0;
  while (input >> line) {
    bool firstd = false;
    int first = 0;
    int second = 0;
    for (char c : line) {
      if (isdigit(c)) {
        if (!firstd) {
          first = c - '0';
          firstd = true;
        }
        second = c - '0';
      }
    }
    sum += first * 10 + second;
  }
  cout << sum;
}

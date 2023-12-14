#include <bits/stdc++.h>

using namespace std;

string valid[] = {"one", "two",   "three", "four", "five",
                  "six", "seven", "eight", "nine"};

int main() {
  ifstream input("input.txt");

  string line;
  int sum = 0;
  while (input >> line) {
    bool firstd = false;
    int first = 0;
    int second = 0;
    for (int i = 0; i < line.length(); ++i) {
      char c = line[i];

      if (isdigit(c)) {
        if (!firstd) {
          first = c - '0';
          firstd = true;
        }
        second = c - '0';
      } else {
        for (int n = 0; n < 9; ++n) {
          string ns = valid[n];
          if (line.length() - i < ns.length())
            continue;
          for (int j = 0; i + j < line.length() && j < ns.length(); ++j) {
            if (line[i + j] != ns[j])
              goto end;
          }
          if (!firstd) {
            first = n + 1;
            firstd = true;
          }
          second = n + 1;
          break;
        end:
        }
      }
    }
    sum += first * 10 + second;
  }
  cout << sum;
}

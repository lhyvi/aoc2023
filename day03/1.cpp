#include <bits/stdc++.h>
#include <ctype.h>
#include <string_view>

using namespace std;

bool is_valid(int line_index, int start, int end, const vector<string> &lines) {
  int mini = max(0, start - 1);
  int maxi = min((int) lines[0].length() - 1, end + 1);
  int minl = max(0, line_index - 1);
  int maxl = min((int) lines.size() - 1, line_index + 1);

  for(int i = minl; i <= maxl; ++i) {
    for(int j = mini; j <= maxi; ++j) {
      if (!isdigit(lines[i][j]) && lines[i][j] != '.')
        return true;
    }
  }
  return false;
}

int main(int argc, char **argv) {
  ifstream input;
  if (argc > 1)
    input = ifstream(argv[1]);
  else
    input = ifstream("input.txt");

  string line;
  vector<string> lines;

  while (getline(input, line)) {
    lines.push_back(line);
  }

  long long int sum = 0;
  for (int i = 0; i < lines.size(); ++i) {
    string_view cline(lines[i]);
    for (int j = 0; j < cline.size(); ++j) {
      if (isdigit(cline[j])) {
        int start = j, end = j;
        while(++j < cline.size() && isdigit(cline[j])) {
          end = j;
        }
        if (is_valid(i, start, end, lines)) {
          int num = 0;
          for(int k = start; k <= end; ++k) {
            num *= 10;
            num += cline[k] - '0';
          }
          sum += num;
        }
      }
    }
  }

  cout << sum;
}

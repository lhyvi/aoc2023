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

int get_num(int line_index, int char_index, const vector<string> &lines) {
  int minl = max(0, line_index - 1);
  int maxl = min((int) lines[0].length() - 1, line_index + 1);
  int minc = max(0, char_index - 1);
  int maxc = min((int) lines.size() - 1, char_index + 1);
  int num1 = 0;

  for(int i = minl; i <= maxl; ++i) {
    string_view line(lines[i]);
    for(int j = minc; j <= maxc; ++j) {
      if(isdigit(line[j])) {
        int s = j, e = j; // find start->end of number
        while(--j >= 0 && isdigit(line[j])) {
          s = j;
        }
        j = e;
        while(++j < line.size() && isdigit(line[j])) {
          e = j;
        }

        int num = 0;
        for(int i = s; i <= e; ++i) {
          num *= 10;
          num += line[i] - '0';
        }

        if (num1)
          return num1 * num;
        else
          num1 = num;
      }
    }
  }

  return 0; // if second number not found, then not gear
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
      if (cline[j] == '*') { // only consider gears
        int num = get_num(i, j, lines);
        sum += num;
      }
    }
  }

  cout << sum;
}

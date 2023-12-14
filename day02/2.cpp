#include <bits/stdc++.h>
#include <limits>

using namespace std;

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14
#define SS_MAX std::numeric_limits<std::streamsize>::max()

int main(int argc, char **argv) {
  ifstream input;
  if (argc > 1)
    input = ifstream(argv[1]);
  else
    input = ifstream("input.txt");

  string line;

  int sum = 0;
  while (getline(input, line)) {
    bool valid = true;

    // Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
    istringstream ss(line);
    int id;
    ss.ignore(SS_MAX, ' ');
    ss >> id;
    ss.ignore(SS_MAX, ':');

    int n;
    string color;
    int colors[3] = {0};
    int max_colors[3] = {0};
    while (ss >> n >> color) {
      bool reset = false;

      if (color.back() == ';')
        reset = true;

      if (color.back() == ';' || color.back() == ',')
        color.pop_back();

      if (color == "red") {
        colors[0] += n;
        if (colors[0] > max_colors[0])
          max_colors[0] = colors[0];
      }
      if (color == "green") {
        colors[1] += n;
        if (colors[1] > max_colors[1])
          max_colors[1] = colors[1];
      }
      if (color == "blue") {
        colors[2] += n;
        if (colors[2] > max_colors[2])
          max_colors[2] = colors[2];
      }

      if (reset) {
        for (int i = 0; i < 3; ++i) {
          colors[i] = 0;
        }
      }
    }

    if (valid)
      sum += max_colors[0] * max_colors[1] * max_colors[2];
  }
  cout << sum;
}

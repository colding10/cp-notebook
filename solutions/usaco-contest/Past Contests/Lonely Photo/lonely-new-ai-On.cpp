#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n < 3) {
    cout << "Error: invalid input" << endl;
    return 1;
  }

  string cows;
  cin >> cows;

  int lonely_photos = 0;
  int h_count = 0;
  int g_count = 0;

  for (int i = 0; i < n; i++) {
    if (cows[i] == 'G') {
      g_count++;
    } else {
      h_count++;
    }

    if (h_count + g_count < 3) {
      continue;
    }

    if (h_count >= 2 && g_count >= 2) {
      break;
    }

    if (h_count == 1 || g_count == 1) {
      lonely_photos++;
    }
  }

  cout << lonely_photos << endl;
  return 0;
}


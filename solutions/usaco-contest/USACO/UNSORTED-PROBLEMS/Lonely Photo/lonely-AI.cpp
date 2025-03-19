#include <bits/stdc++.h>
using namespace std;

int is_lonely(map<char, int> photo) {
  return photo['H'] == 1 || photo['G'] == 1;
}

int is_safe(map<char, int> photo) {
  return photo['H'] >= 2 && photo['G'] >= 2;
}

int main() {
  int n;
  cin >> n;

  vector<char> cows(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i];
  }

  int lonely_photos = 0;
  map<char, int> current_photo;

  for (int i = 0; i < n - 2; i++) {
    current_photo = {{'G', 0}, {'H', 0}};
    current_photo[cows[i]]++;

    for (int j = i + 1; j < n; j++) {
      current_photo[cows[j]]++;

      if (current_photo['G'] + current_photo['H'] < 3) {
        continue;
      }

      if (is_safe(current_photo)) {
        break;
      }

      if (is_lonely(current_photo)) {
        lonely_photos++;
      }
    }
  }

  cout << lonely_photos << endl;

  return 0;
}

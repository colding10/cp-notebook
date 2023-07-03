#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1005
#define MAXX int(10e5)

int dp[MAXN] = {};
vector<int> book_prices;
vector<int> book_lengths;
vector<int> books;

int main() {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    books.push_back(a);
  }

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    book_lengths.push_back(a);
  }
}

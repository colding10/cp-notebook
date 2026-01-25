#include <iostream>
#include <set>
#include <vector>

using namespace std;

int floodfill()

int main() {
    int n;
    cin >> n;

    int val;
    int graph[n][n];
    set<int> numbers;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            cin >> val;
            if (!(numbers.find(val) != numbers.end())) {
                numbers.insert(val);
            }

            graph[i][j] = val;
        }
    }


}
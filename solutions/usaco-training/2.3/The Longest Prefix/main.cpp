/*
ID: colindi1
LANG: C++
TASK: prefix
*/

#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    unordered_set<string> primset;

    string cur;
    fin >> cur;
    while (cur != ".") {
        primset.insert(cur);
        fin >> cur;
    }

    string sequence;
    while (!fin.eof()) {
        string str;
        fin >> str;
        sequence += str;
    }

    int size = (int)sequence.size();
    vector<int> dp(size, 0);
    if (primset.count(sequence.substr(size - 1))) {
        dp[size - 1] = 1;
    }

    for (int i = size - 1; i >= 0; i--) {
        for (int j = i + 1; j <= i + 10 && j < size; j++) {
            string s = sequence.substr(i, j - i);

            if (primset.count(s)) {
                dp[i] = max(dp[i], dp[j] + j - i);
            }
        }
    }

    fout << dp[0] << endl;

    return 0;
}
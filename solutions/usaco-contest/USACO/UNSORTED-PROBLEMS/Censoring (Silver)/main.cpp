#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string s, t;
    fin >> s >> t;
    int n = t.length();

    string censored = "";

    for (char c : s) {
        censored += c;

        if (censored.length() > n) {
       		if (censored.substr(censored.length() - n) == t) {
            	censored.erase(censored.length() - n);
        }
        }
    }

    fout << censored << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool balanced(string expr) {
    vector<char> stack;

    for (char c : expr) {
        if (c == '(') {
            stack.push_back(c);
        } else {
            if (stack.empty()) {
                return false;
            }
            char current_char = stack.back();
            stack.pop_back();
            if (current_char == '(' && c != ')') {
                return false;
            }
        }
    }

    return stack.empty();
}

int count_ = 0;

void recurse(string expr) {
    if (expr.find('?') == string::npos) {
        if (balanced(expr)) {
            count_++;
        }
        return;
    }

    int missing_idx = expr.find('?');
    if (std::count(expr.begin(), expr.begin() + missing_idx, ')') >
        std::count(expr.begin(), expr.begin() + missing_idx, '(')) {
        return;
    }
    
    string e1 = expr;
    string e2 = expr;

    e1[missing_idx] = ')';
    e2[missing_idx] = '(';

    recurse(e1);
    recurse(e2);
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string e;
    for (char c : s) {
        e += c;
        e += '?';
    }
    recurse(e);
    cout << count_ << endl;
    return 0;
}

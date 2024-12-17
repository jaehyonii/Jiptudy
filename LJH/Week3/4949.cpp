#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;

    while (true) {
        getline(cin, line);
        if (line == ".") {
            break;
        }

        stack<char> stk;
        bool check = true;

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '[' || line[i] == '(') {
                stk.push(line[i]);
            }
            if (line[i] == ']') {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
            if (line[i] == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
        }

        if (!stk.empty()) {
            check = false;
        }

        if (check) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}

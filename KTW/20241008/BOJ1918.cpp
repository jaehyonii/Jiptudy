#include <bits/stdc++.h>

using namespace std;

char brak[] = {'(', ')', '\0'};
char giho[] = {'*', '/', '+', '-', '\0'};

int main() {
    string s, ans;
    char ch;
    stack <char> stk;
    
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (!strchr(brak, s[i]) && !strchr(giho, s[i]))
            ans.push_back(s[i]);
        else if (s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == '*' || s[i] == '/'){
            while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                ch = stk.top();
                stk.pop();
                ans.push_back(ch);
            }
            stk.push(s[i]);
        } else if (s[i] == '+' || s[i] == '-') {
            while (!stk.empty() && strchr(giho, stk.top())) {
                ch = stk.top();
                stk.pop();
                ans.push_back(ch);
            }
            stk.push(s[i]);
        } else {
            while (!stk.empty() && stk.top() != '(') {
                ch = stk.top();
                stk.pop();
                ans.push_back(ch);
            }
            if (!stk.empty())
                stk.pop();
        }
    }
    while (!stk.empty()) {
        ch = stk.top();
        stk.pop();
        ans.push_back(ch);
    }
    cout << ans;
    return 0;
}
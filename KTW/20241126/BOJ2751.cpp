#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> v;
    int num, n;
    
    cin >> num;
    while (num>0) {
        cin >> n;
        v.push_back(n);
        num--;
    }
    sort(v.begin(), v.end());
    for (auto itr = v.begin(); itr != v.end(); itr++)
        cout << *itr << "\n";
    return 0;
}
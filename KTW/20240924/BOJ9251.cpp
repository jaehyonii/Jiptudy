#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a, b;
    
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    vector <vector <int> > table(m+1, vector<int>(n+1, 0));
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n;j++) {
            if (a[i-1] == b[j-1])
                table[i][j] = 1 + table[i-1][j-1]; // last word match
            else
                table[i][j] = max(table[i][j-1], table[i-1][j]);
        }
    }
    cout << table[m][n];
    return 0;
}
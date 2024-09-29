#include <bits/stdc++.h>

using namespace std;

int main() {
    char arr[1000001] = {0};
    int m, n, limit, div;
    
    arr[1] = 1;
    cin >> m >> n;
    limit = (int)sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (arr[i])
            continue;
        for (int j = i*2; j <= n; j += i)
            arr[j] = 1;
    }
    for (int i = m; i <= n; i++)
    {
        if (!arr[i])
            cout << i << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <pair<int, int> > bags;
    int n, k, w ,v;
    
    cin >> n >> k;
    vector <int> dp(k+1, 0);
    vector <int> cpy;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        bags.push_back(make_pair(w, v));
    }
 
    for (auto itr=bags.begin(); itr != bags.end(); itr++) {
        cpy = dp;
        n = itr->second; // 새 값이 기존 값보다 크든 작든 갱신에는 반영
        for (int i = 1; i + itr->first <= k; i++) {
            if (cpy[i] + n > cpy[i+itr->first])
                dp[i+itr->first] = cpy[i] + n;
        }
        if (itr->first <= k && dp[itr->first] < itr->second) // K보다 무거운 물건 예외 처리
            dp[itr->first] = itr->second;
    }
    
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
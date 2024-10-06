#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

bool impossible(int n1, int idx1, int n2, int idx2) {
    return (n1 == n2 || n2 - n1 == idx2 - idx1 || n2 - n1 == idx1 - idx2);
}

void nqueen(int *arr, int cur, int len) {
    bool flag;
    if (cur == len) {
        cnt++;
        return ;
    }
    for (int cur_num = 0; cur_num < len; cur_num++) {
        flag = true;
        for (int prev_idx = 0; prev_idx < cur; prev_idx++) {
            if (impossible(cur_num, cur, arr[prev_idx], prev_idx))
                flag = false;
        }
        if (flag) {
            arr[cur] = cur_num;
            nqueen(arr, cur + 1, len);
        }
    }
}

int main() {
    int arr[14];
    int num;
    
    cin >> num;
    nqueen(arr, 0, num);
    cout << cnt;
    return 0;
}
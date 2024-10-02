#include <bits/stdc++.h>
using namespace std;

int n, r, c, S;
int result = 0;

void divide_conquer(int y, int x, int S) {
    // y: 현재 기준 row, x: 현재 기준 col, S: 현재 한 변의 길이

    if (S == 1) {
        // 최소 분할 단위로 도착했을 때
        return; //종료
    }

    int half = S / 2;

    if (r < y + half && c < x + half) {
        // 1사분면
        divide_conquer(y, x, half);
    }
    else if (r < y + half && c >= x + half) {
        // 2사분면
        result += half * half; //result update
        divide_conquer(y, x + half, half);
    }
    else if (r >= y + half && c < x + half) {
        // 3사분면
        result += 2 * half * half; //result update
        divide_conquer(y + half, x, half);
    }
    else {
        // 4사분면
        result += 3 * half * half; //result update
        divide_conquer(y + half, x + half, half);
    }
}

int main() {
    cin >> n >> r >> c;

    S = pow(2, n);
    divide_conquer(0, 0, S);

    cout << result;

    return 0;
}

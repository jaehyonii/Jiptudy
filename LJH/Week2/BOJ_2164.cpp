#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();  // 맨 앞의 카드 제거
        q.push(q.front());  // 다음 카드를 뒤로 이동
        q.pop();  // 맨 앞의 카드 제거
    }

    cout << q.front();  // 남은 마지막 카드 출력
    return 0;
}

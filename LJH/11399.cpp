#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end()); // 오름차순 정렬

    int result = 0;
    int sum = 0; // 누적 시간을 저장할 변수
    for (int i = 0; i < n; i++) {
        sum += arr[i];   // 현재 사람까지의 대기 시간
        result += sum;   // 지금까지의 대기 시간을 총합에 추가
    }
    cout << result;

    return 0;
}

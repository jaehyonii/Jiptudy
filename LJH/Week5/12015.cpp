#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> lis(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis[0] = arr[0];
	int maxIndex = 1;

	for (int i = 1; i < n; i++) {
		int now = arr[i];
		if (lis[maxIndex - 1] < now) {
			lis[maxIndex] = now;
			maxIndex++;
		}
		else {
			int start = 0, end = maxIndex;
			while (start < end) {
				int mid = (start + end) / 2;
				if (lis[mid] < now) {
					start = mid + 1;
				}
				else end = mid;
			}
			lis[end] = now; // end로 해도 동일
		}
	}

	cout <<  maxIndex;
	return 0;
}
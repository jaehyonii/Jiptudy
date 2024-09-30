#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr;
	int k = 0;

	cin >> k;

	for (int i = 0; i < k; i++) {
		int a = 0;
		cin >> a;
		if (a == 0) arr.pop_back();
		else {
			arr.push_back(a);
		}
	}
	int result = 0;
	for (int i = 0; i < arr.size(); i++) {
		result += arr.at(i);
	}
	cout << result;
	return 0;
}
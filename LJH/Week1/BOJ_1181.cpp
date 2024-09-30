#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main() {
	vector<string>arr;
	string str;
	int n = 0;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		arr.push_back(str);
	}
	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		if (i != 0 && arr[i] == arr[i - 1]) continue;
		cout << arr[i];
		if(i!=n-1)cout<<endl;
	}
	return 0;
}
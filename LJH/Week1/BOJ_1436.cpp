#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	string temp;
	int now = 0;
	int a = 0;
	while (1) {
		temp = to_string(now);
		if (temp.find("666") != string::npos) {
			a++;
			if (a == n) {
				break;
			}
		}
		now++;
	}
	cout << now;

	return 0;
}
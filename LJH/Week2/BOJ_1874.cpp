#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	stack<int> stk; // Stack
	vector<bool> cmd; // True: Push, False: Pop
	int val = 0; // Value what i focus
	int cnt = 1; // Push Count

	for (int i = 0; i < n; i++) {
		cin >> val;
		while (cnt <= val) {
			stk.push(cnt);
			cmd.push_back(true);
			cnt++;
		}

		if (stk.top() == val) {
			stk.pop();
			cmd.push_back(false);
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd.at(i)) cout << "+\n";
		else cout << "-\n";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int a = 0, b = 0;
	cin >> a >> b;
	queue<pair<long long,long long>> q;
	long long current = 0;
	q.push(make_pair(a,current));

	while (!q.empty()) {
		long long now = q.front().first;
		current = q.front().second+1;
		q.pop();
		
		if (now == b) {
			cout << current;
			return 0;
		}

		if (now * 2 <= b) {
			q.push(make_pair(now * 2,current));
		}
		if (now * 10+1 <= b) {
			q.push(make_pair(now * 10+1,current));
		}
	}
	cout << -1;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	string str = to_string(a * b * c);
	int check[10] = {0, };
	for (int i = 0; i < str.size(); i++) {
		check[str[i]-'0']++;
	}
	for (int i = 0; i < 10; i++) cout << check[i] << endl;
	return 0;
}
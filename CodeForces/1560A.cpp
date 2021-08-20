#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int k;
	cin >> k;
	int num = 0;
	while(k--) {
		num++;
		while((num) % 3 == 0 || num % 10 == 3)
			num++;
	}
	cout << num;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}
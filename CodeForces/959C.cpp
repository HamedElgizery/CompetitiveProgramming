#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	if (N < 6) {
		cout << -1 << '\n';
	}
	else {
		cout << "1 2\n";
		cout << "1 3\n";
		cout << "1 4\n";
		for (int i = 5; i <= N; i++) {
			cout << "2 " << i << '\n';
		}
	}
	for (int i = 1; i < N; i++) {
		cout << i << ' ' << i+1 << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
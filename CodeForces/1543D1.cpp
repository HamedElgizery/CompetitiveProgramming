#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const bool testing = false;
int x;
bool q(int y) {
	if (y == x)
		return 1;
	x ^= y;
	return 0;
}

int n, k;
void solve() {
	cin >> n >> k;
	if (testing)
		cin >> x;
	int curr = 0;
	bool turn = false;
	for (int i = 0; i < n; i++) {
		int r;
		// cerr << curr << endl;
		curr ^= i;
		if (testing) {
			r = q(curr);
		}
		else {
			cout << curr << endl;
			cin >> r;
		}
		if (r) {
			if (testing) cout << curr << endl;
			break;
		}
		if (i)
			curr ^= (i-1);
		turn = !turn;
	}
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
	}
}
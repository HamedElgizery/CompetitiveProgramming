#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5;
int n;
int x[N];
int ans[N];

pair<int, int> match(int curr, int num) {
	pair<int, int> ret = {num, 0};
	for (int i = 0; i < 30; i++) {
		if (curr&(1<<i)) {
			if (!(num&(1<<i))) {
				ret.first |= (1<<i);
				ret.second |= (1<<i);
			}
		}
	}
	return ret;
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	int curr = x[0];
	for (int i = 1; i < n; i++) {
		pair<int, int> res = match(curr, x[i]);
		curr = res.first;
		ans[i] = res.second;
	}

	for (int i = 0; i < n; i++) 
		cout << ans[i] << ' ';
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
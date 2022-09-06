#include <bits/stdc++.h>

using namespace std;


void solve() {
	int N, D;
	cin >> N >> D;

	vector<int> A(N); for (auto &a : A) cin >> a;
	vector<bool> vis(N, 0);
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;

		vector<bool> states;
		for (int j = i; !vis[j]; (j+=D)%=N) {
			states.push_back(A[j]);
			vis[j] = 1;
		}

		int statesSz = states.size();
		for (int j = 0; j < statesSz; j++)
			states.push_back(states[j]);

		int firstZero = -1;
		for (int j = 0; j < statesSz; j++) {
			if (!states[j]) {
				firstZero = j;
				break;
			} 
		}

		if (!(~firstZero)) {
			ans = -1;
			break;
		}

		int cnt = 0;
		for (int j = firstZero; j < states.size(); j++) {
			if (!states[j])
				ans = max(ans, cnt-1), cnt = 0;
			cnt++;
		}
	}
	cout << ans;
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
	return 0;
}
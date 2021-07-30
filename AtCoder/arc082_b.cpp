#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	vector<int> P(N); for (auto& p : P) cin >> p, --p;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (P[i] == i)
			ans++, swap(P[i], (i+1 < N ? P[i+1] : P[i-1]));
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
	solve();
}
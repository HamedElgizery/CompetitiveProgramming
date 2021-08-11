#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	vector<pair<int, int>> L(N), R(N);

	for (int i = 0; i < N; ++i) {
		cin >> L[i].first >> R[i].first;
		L[i].second = R[i].second = i;
	}

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int ans = INT_MIN;

	for (int i = 0; i < N; i++) {
		int LMX = N-1, RMN = 0;

		if (L[LMX].second == i) LMX--;
		if (R[RMN].second == i) RMN++;

		ans = max(ans, max(0, R[RMN].first - L[LMX].first));
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
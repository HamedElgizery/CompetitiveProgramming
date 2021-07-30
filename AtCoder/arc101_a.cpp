#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;

void solve() {
	cin >> N >> K;
	vector<int> line(N); for (auto& it : line) cin >> it;

	int ans = INT_MAX;
	for (int l = 0; l + K - 1 < N; l++) {
		int tmp = INT_MAX;
		int r = l + K - 1;

		if (line[r] <= 0)
			tmp = abs(line[l]);

		else if (line[l] >= 0)
			tmp = abs(line[r]);

		else 
			tmp = min(abs(line[l])*2 + abs(line[r]), abs(line[r])*2 + abs(line[l]));
		

		ans = min(ans, tmp);
	}
	cout << ans << endl;
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
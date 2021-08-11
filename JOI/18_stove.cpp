#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, K;
	cin >> N >> K; 
	int ans = N;
	vector<int> T(N); for (auto& t : T) cin >> t;
	vector<int> diff;

	for (int i = 0; i+1 < N; i++) 
		diff.push_back(T[i+1] - T[i] - 1);

	sort(diff.begin(), diff.end());

	for (auto it : diff)
		ans += it;

	for (int i = diff.size()-1; K > 1 && i > 0; --K, --i) {
		ans -= diff[i];
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
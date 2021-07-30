#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K, X;

int fun(vector<int> R) {
	int ret = 0;
	vector<int> G;
	for (int i = 0; i < R.size(); i++) {
		G.push_back(R[i]);
		int idx = G.size();
		if (idx < 3 || i+1 < R.size() && R[i] == R[i+1])
			continue;
		int x = G.back();
		if (G[idx-1] == G[idx-2] && G[idx-2] == G[idx-3])
			while(G.size() && G.back() == x)
				G.pop_back(), ret++;

	}
	return max(ret-1, 0);
}



void solve() {
	cin >> N >> K >> X;
	vector<int> R(N); for (auto& r : R) cin >> r;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		R.insert(R.begin()+i, X);
		ans = max(ans, fun(R));
		R.erase(R.begin()+i);
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
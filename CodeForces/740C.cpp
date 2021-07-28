#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int mex = INT_MAX, n, m;
	cin >> n >> m;

	vector<pair<int, int>> RANGES(m); 
	for (auto& it : RANGES) {
		cin >> it.first >> it.second;
		mex = min(mex, it.second - it.first + 1);
	}

	cout << mex << endl;
	for (int i = 1; i <= n; i++)
		cout << i%mex << ' ';
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
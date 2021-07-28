#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> STAND(n); for (auto& p : STAND) cin >> p.first >> p.second;
	for (auto it : STAND) {
		if (it.first != it.second) {
			cout << "rated";
			return;
		}
	}
	int prev = 1e9;
	for (auto p : STAND) {
		if (p.first > prev) {
			cout << "unrated";
			return;
		}
		prev = p.first;
	}
	cout << "maybe";
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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int n, p;
	cin >> n >> p;

	vector<pair<pair<ll, ll>, ll>> RANGES(n);
	for (auto& it : RANGES) {
		cin >> it.first.first >> it.first.second;
		it.second = (it.first.second/p) - ((it.first.first-1)/p);
	}

	double ans = 0;
	for (int i = 0; i < n; i++) {
		int l1 = RANGES[i].first.second -  RANGES[i].first.first+1;
		int l2 = RANGES[(i+1)%n].first.second - RANGES[(i+1)%n].first.first+1;
		ans += (RANGES[i].second*1.0/l1);
		ans += (RANGES[(i+1)%n].second*1.0/l2);
		ans -= ((RANGES[i].second*1.0/l1)*(RANGES[(i+1)%n].second*1.0/l2));
 	}

	cout << fixed << setprecision(10) << 2000.0 * ans;
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
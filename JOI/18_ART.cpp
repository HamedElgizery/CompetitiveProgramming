#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;

	vector<pair<ll, ll>> AB(N);

	for (int i = 0; i < N; ++i)
		cin >> AB[i].first >> AB[i].second;


	sort(AB.begin(), AB.end());

	for (int i = 1; i < N; i++)
		AB[i].second += AB[i-1].second;

	ll ans = AB[0].second;
	for (int l = 0, r = 1; r < N; ++r) {
		ll tmp1 = AB[r].second - (l ? AB[l-1].second : 0LL) - AB[r].first + AB[l].first;
		ll tmp2 = AB[r].second - AB[r-1].second;
		if (tmp2 >= tmp1) l = r;
		ans = max({ans, tmp1, tmp2});
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
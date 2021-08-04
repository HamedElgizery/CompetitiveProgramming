#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll s1[] = {1, -1, 1, -1};
ll s2[] = {1, 1, -1, -1};

bool valid(vector<ll>& res, ll K) {
	ll mn = *min_element(res.begin(), res.end());
	if (mn >= 0)
		mn = 0;
	ll atLeast = 3*abs(mn);
	for (auto it : res) atLeast += it;
	K -= atLeast;
	return (K >= 0 && K % 3 == 0);
}


void solve() {
	ll N, K, D1, D2;
	cin >> N >> K >> D1 >> D2;

	bool ans = 0;
	for (ll s = 0; s < 4; s++) {
		vector<ll> res = {D2*s2[s] + D1*s1[s], D2*s2[s], 0};
		if (!valid(res, K))
			continue;

		ll mx = 0;
		for (ll i = 0; i < 3; i++)
			mx = max(mx, res[i]);

		ll MatchesNeeded = 0;
		for (ll i = 0; i < 3; i++) {
			MatchesNeeded += abs(res[i] - mx);
		}
		ll left = (N - K) - MatchesNeeded ;
		ans |= (left >= 0 && left % 3 == 0);
	}

	cout << (ans ? "yes" : "no") << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
		solve();
}
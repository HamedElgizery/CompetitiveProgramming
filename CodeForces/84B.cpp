#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	
	vector<int> A(N); for (auto& a : A) cin >> a;

	ll ans = 0;
	int r = 0, c = 1;
	while(r < N) {
		int l = r;
		while(r < N && A[r] == A[l])
			r++;
		ll c = (r - l);
		ans += c*(c+1)/2;
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
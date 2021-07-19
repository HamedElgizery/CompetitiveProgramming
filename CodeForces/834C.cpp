#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<bool, int> CUBIC(ll a, ll b) { 
	ll l = 1, r = 2e6, mid;
	while(l <= r) {
		mid = (l+r)>>1;
		if (mid*mid*mid == a*b)
			return {1, mid};
		if (mid*mid*mid > a*b)
			r = mid-1;
		else
			l = mid+1;
	}
	return {l*l*l == a*b, l};
}


void solve() {
	int a, b;
	cin >> a >> b;
	pair<bool, int> cube = CUBIC(a, b);
	if (!cube.first) {
		cout << "No";
		return;
	}
	if (a%cube.second == 0 && b%cube.second == 0) {
		cout << "Yes";
		return;
	}
	cout << "No";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}
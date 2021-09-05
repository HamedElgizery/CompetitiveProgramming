#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5+10;
int N, C;
int a[mxN], b[mxN];

ll fun(int idx, ll money) {
	ll needFin = max(0LL, C - money);
	ll needNex = max(0LL, b[idx] - money);
	ll toFin = (needFin+a[idx]-1)/a[idx];
	ll toWNex = (needNex+a[idx]-1)/a[idx];
	if (idx == N-1)
		return toFin;
	return min(toFin,
	 toWNex + fun(idx+1, toWNex*a[idx] + money - b[idx]) + 1);
	return 0;
}

void solve() {
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i+1 < N; i++)
		cin >> b[i];

	cout << fun(0, 0) << endl;
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
	while(t--) 
		solve();
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int MOD = 1e9+7;
int n;

ll FP(int x, int y, int m) {
	if (y == 0)
		return 1;
	ll tmp = FP(x, y>>1, m);
	return (((tmp*tmp)%m)*(y&1 ? x : 1))%m;
} 

void solve() {
	cin >> n;
	cout << FP(3, FP(3, n, MOD-1), MOD);
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("triangle.in", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		long long u, r, x;
		cin >> u >> r >> x;
		r <<= 1;
		x -= u;
		if (x % r || x < 0) {
			cout << -1 << endl;
			continue;
		}
		x /= r;
		long long st = 1, en = 1e9, mid;
		while(st < en) {
			mid = (st+en+1) >> 1LL;
			if (mid*(mid-1) <= x*2LL) st = mid;
			else en = mid - 1;
		}
		cout << st << ' ' << (x - (st*(st-1)/2))+1 << endl;
	}
}
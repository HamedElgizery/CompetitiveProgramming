#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("sell.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		long long d, p, c, ans = 0;
		cin >> n >> d;
		while(n--) {
			cin >> p >> c;
			ans += max(p,p + c * d);
		}
		cout << ans << endl;
	}
}
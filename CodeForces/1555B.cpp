#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int W, H, x1, y1, x2, y2, w, h;
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

	int ans = INT_MAX;

	if (x2 - x1 + w <= W)
		ans = min(ans, min(max(0, w - x1), max(0, x2 - (W - w))));

	if (y2 - y1 + h <= H) 
		ans = min(ans, min(max(0, h - y1), max(0, y2 - (H - h))));

	if (ans == INT_MAX) ans = -1;

	cout << fixed << setprecision(12) << ans*1.0;
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
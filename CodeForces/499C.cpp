#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
struct point {
	ll x, y;
	point() {x = 0, y = 0;}
} H, S;
ll a, b, c;

bool check() {
	double f = a * H.x + b * H.y + c;
	double s = a * S.x + b * S.y + c;
	if (f < 0)
		swap(f, s);
	if (f > 0 && s < 0)
		return 1;
	return 0;
}

void solve() {
	int ans = 0;
	cin >> H.x >> H.y >> S.x >> S.y >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		ans += check();
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
}

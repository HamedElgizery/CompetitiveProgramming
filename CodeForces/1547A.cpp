#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct point
{
	int x, y;
} A, B, F;

bool bety() {
	int ymn = min(A.y, B.y), ymx = max(A.y, B.y);
	if (F.y > ymn && F.y < ymx && F.x == A.x)
		return 1;
	return 0;
}

bool betx() {
	int xmn = min(A.x, B.x), xmx = max(A.x, B.x);
	if (F.x > xmn && F.x < xmx && F.y == A.y)
		return 1;
	return 0;
}

void solve() {
	cin >> A.x >> A.y >> B.x >> B.y >> F.x >> F.y;
	int diffx = abs(A.x - B.x);
	int diffy = abs(A.y - B.y);
	int ans = diffy + diffx;
	if (diffx == 0) {
		ans += 2 * bety();
	}
	if (diffy == 0) {
		ans += 2 * betx();
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
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}
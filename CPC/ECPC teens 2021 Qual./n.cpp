#include <bits/stdc++.h>
using namespace std;
struct Point {
	int x, y;
};
int main() {
	freopen("touhin.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		Point pa, bm;
		int k;
		cin >> pa.x >> pa.y >> bm.x >> bm.y >> k;
		int x = abs(pa.x - bm.x), y = abs(pa.y - bm.y);
		if (k) {
			if (!(x % k) && !(y % k))
				cout << "YES\n";
			else
				cout << "NO\n";
		} else if (!x && !y)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a, b;

void solve() {
	cin >> a >> b;
	set<int> CD;
	int g = gcd(a, b);
	for (int i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			CD.insert(i);
			CD.insert(g/i);
		}
	}
	int n;
	cin >> n;
	while(n--) {
		int lw, hg;
		cin >> lw >> hg;
		auto it = CD.upper_bound(hg);
		if (it != CD.begin() && *prev(it) >= lw && *prev(it) <= hg) {
			cout << *prev(it) << endl;;
		}
		else {
			cout << -1 << endl;
		}
	}
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
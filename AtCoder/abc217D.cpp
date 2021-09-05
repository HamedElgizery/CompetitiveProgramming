#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set<int> cuts;

void solve() {
	int L, Q;
	cin >> L >> Q;
	cuts.insert(0);
	cuts.insert(L);
	while(Q--) {
		int c, x;
		cin >> c >> x;
		if (c == 1)
			cuts.insert(x);
		else {
			auto it = cuts.lower_bound(x);
			cout << (*it - *prev(it)) << endl;
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
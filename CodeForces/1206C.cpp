#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	if (N&1^1) return void(cout << "NO");
	cout << "YES\n";

	vector<int> ans(2*N);
	for (int i = 0, x = 1; i < N; i++, x+=2) {
		if (i&1)
			ans[i] = x+1, ans[i+N] = x;
		else
			ans[i] = x, ans[i+N] = x+1;
	}
	for (auto it : ans) {
		cout << it << ' ';
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
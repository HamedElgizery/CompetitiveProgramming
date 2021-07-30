#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int A, B, C;
	cin >> A >> B >> C;

	bool ans = 0;

	for (int X = 0; X < 1000 && !ans; X++)
		ans |= ((X*B + C) % A == 0);

	cout << (ans ? "YES" : "NO");
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
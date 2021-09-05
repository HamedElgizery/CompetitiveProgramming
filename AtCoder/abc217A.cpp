#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	string s, t;
	cin >> s >> t;
	cout << (s < t ? "Yes" : "No");
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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double n, p;

void solve() {
	cout << fixed << setprecision(0) <<  pow(p, 1/n) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> p)
		solve();
}
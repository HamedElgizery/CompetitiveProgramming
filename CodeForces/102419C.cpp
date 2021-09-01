#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int fact(int n) {
	int ret = 1;
	for (int i = 2; i * i <= n; i++) {
		while(n%i == 0) {
			n/=i;
			ret += i - 1;
		}
	}
	ret += n - 1;
	return ret;
}

void solve() {
	int n;
	cin >> n;
	cout << fact(n) << endl;
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
	while(t--)
		solve();
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5;
ll arr[N], n;
void solve() {
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i], sum += arr[i];
	}
	ll rem = sum % n;
	cout << (rem * (n-rem));
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
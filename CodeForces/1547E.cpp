#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e5+100;
int n, k, a[N], t[N];
pair<int, int> c[N];
int ans[N];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> c[i].first;
	for (int i = 0; i < k; i++) 
		cin >> c[i].second;
	sort(c, c+k);
	for (int i = 0; i < k; i++) {
		a[i] = c[i].first;
		t[i] = c[i].second;
	}
	a[k] = n+10;
	t[k] = INT_MAX;
	for (int i = 1; i < k; i++) {
		t[i] = min(t[i], t[i-1]+abs(a[i] - a[i-1]));
	}
	for (int i = k-2; i >= 0; i--) {
		t[i] = min(t[i], t[i+1]+abs(a[i] - a[i+1]));
	}

	for (int i = 1; i <= a[0]; i++) {
		ans[i] = abs(i-a[0]) + t[0];
	}
	for (int i = a[k-1]; i <= n; i++) {
		ans[i] = abs(i-a[k-1]) + t[k-1];
	}


	for (int i = 1; i < k; i++) {
		for (int j = a[i-1]; j <= a[i]; j++) {
			ans[j] = min(t[i-1]+abs(a[i-1]-j), t[i]+abs(a[i]-j));
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
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
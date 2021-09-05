#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, pi;
	cin >> N;
	vector<int> q(N);
	for (int i = 0; i < N; i++) {
		cin >> pi;
		q[pi-1] = i+1;
	}
	for (auto it : q) {
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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	map<int, int> MP;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		MP[num]++;
	}
	int ans = 0;
	for (auto it : MP) {
		if (it.first > it.second)
			ans += it.second;
		else
			ans += it.second - it.first;
	}
	cout << ans << endl;
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
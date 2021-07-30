#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<int, int> MP;
int N, tmp;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		MP[tmp]++;
		MP[tmp+1]++;
		MP[tmp-1]++;
	}
	
	int ans = 0;
	for (auto it : MP)
		ans = max(ans, it.second);

	cout << ans;
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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e4;
int ans[mxN];

int OR(int i, int j) {
	cout << "or " << i << ' ' << j << endl;
	int ret;
	cin >> ret;
	return ret;
}
int AND(int i, int j) {
	cout << "and " << i << ' ' << j << endl;
	int ret;
	cin >> ret;
	return ret;
}

int ab(int i, int j) {
	if (i > j) swap(i, j);
	return OR(i, j) + AND(i, j);
}

void solve() {
	int N, K;
	cin >> N >> K;

	int x = ab(1, 2), y = ab(1, 3), z = ab(2, 3);
	ans[0] = (x+y-z)/2;
	ans[1] = x - ans[0];
	ans[2] = y - ans[0];

	for (int i = 3; i < N; i++)
		ans[i] = ab(1, i+1) - ans[0];

	sort(ans, ans+N);

	cout << "finish " << ans[K-1] << endl;
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
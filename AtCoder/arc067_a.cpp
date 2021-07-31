#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
int N;
ll ans = 1;
map<int, ll> PF;
void factorize(int n) {
	for (int i = 2; i * i <= n; i++) {
		while(n%i == 0) {
			n/=i;
			PF[i]++;
		}
	}
	if (n > 1)
		PF[n]++;
}

void solve() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		factorize(i);
	}
	for (auto it : PF) {
		(ans *= (it.second+1)) %= MOD;
	}
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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5+10;

ll suffix[mxN];

void solve() {
	int N, K;
	scanf("%d%d", &N, &K);
	int clevel = INT_MIN, tlevel = INT_MAX;

	int h;
	for (int i = 0; i < N; i++) {
		scanf("%d", &h);
		clevel = max(clevel, h);
		tlevel = min(tlevel, h);
		suffix[h-1]++;
	}

	for (int i = mxN-2; ~i; i--)
		suffix[i] += suffix[i+1];

	int ans = 0;
	while(clevel > tlevel) {
		ans++;
		ll sum = 0;
		while(clevel > tlevel && sum + suffix[clevel-1] <= K)
			sum += suffix[--clevel];
	}


	printf("%d", ans);
}	

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	solve();
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long N, K;
	scanf("%lld%lld", &N, &K);
	vector<bool> found(50, 0);
	for (int j = 1; j < 50 && j <= K; j++) {
		if (found[N % j])
			return void(puts("NO"));
		found[N % j] = 1;
	} 
	puts("YES");
}	

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}

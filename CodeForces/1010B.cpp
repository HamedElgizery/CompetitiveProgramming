#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int query(int mid) {
	cout << mid << endl;
	int resp;
	cin >> resp;
	if (resp == -2 || resp == 0)
		exit(0);
	return resp;
}

void solve() {
	int M, N;
	cin >> M >> N;

	bool P[N];
	for (int i = 0; i < N; i++) {
		int resp = query(M);
		P[i] = !(~resp);
	}

	int l = 1, r = M, mid;
	int queID = 0;
	for (int q = 0;;++q) {
		mid = (l+r)>>1;
		int res = query(mid) * (P[q%N] ? 1 : -1);
		if (res == -1)
			r = mid-1;
		else 
			l = mid+1;
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
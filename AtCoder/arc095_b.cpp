#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool better(int a, int aj, pair<int, int> mid) {
	if (min(abs(a - mid.first), abs(a - mid.second)) < min(abs(aj - mid.first), abs(aj - mid.second)))
		return 1;
	return 0;
}

void solve() {
	int N;
	cin >> N;

	vector<int> A(N); for (auto& a : A) cin >> a;
	sort(A.begin(), A.end());

	int ai = A.back(), aj = A[0];

	for (int i = 0; i+1 < N; i++) {
		pair<int, int> mid = {ai/2, (ai+1)/2};
		if (better(A[i], aj, mid))
			aj = A[i];
	}

	cout << ai << ' ' << aj;
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
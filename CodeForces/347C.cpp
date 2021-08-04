#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	return (a == 0 ? b : gcd(b % a, a));
}


void solve() {
	int N, d = 0;
	cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a, d = gcd(d, a);
	cout << ((*max_element(A.begin(), A.end())/d - N) % 2 ? "Alice" : "Bob");
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
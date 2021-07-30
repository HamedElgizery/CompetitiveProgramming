#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int G, S;

void solve() {
	if (min(G, S) == 0) {
		cout << "Ollie wins\n";
		return;
	}
	
	vector<pair<int, bool>> P;
	while(min(G, S)) {
		if (G < S)
			swap(G, S);
		P.push_back({G/S, 0});
		G-=(G/S)*S;
	}

	P.back().second = 1;
	for (int i = P.size()-2; i >= 0; i--)
		P[i].second = (P[i].first == 1 ? !P[i+1].second : 1);

	cout << (P[0].second ? "Stan wins" : "Ollie wins") << '\n'; 
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> G >> S && (G+S))
		solve();
}
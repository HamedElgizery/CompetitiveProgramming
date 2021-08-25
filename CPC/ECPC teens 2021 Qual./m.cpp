#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("bowling.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if((n / 5) + bool(n % 5) <= (n / 10) + bool(n % 10))
			cout << "Omar\n";
		else
			cout << "Eltony\n";
	}
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int, vector<string>>> lines1, lines2;
map<string, string> to;
void solve() {
	int N1;
	cin >> N1;
	for (int i = 0; i < N1; i++) {
		string type;
		cin >> type;
		if (type == "define") {
			string variable;
			cin >> variable;
			lines1.push_back({0, {variable}});
		}
		else if (type == "read") {
			string variable;
			cin >> variable;
			lines1.push_back({1, {variable}});
		}
		else if (type == "print") {
			string variable;
			cin >> variable;
			lines1.push_back({2, {variable}});
		}
		else {
			int brk1 = 0;
			for (; type[brk1] != '='; brk1++)
				continue;
			string var1 = type.substr(0, brk1);
			int brk2 = 0;
			for (; type[brk2] != '+'; brk2++)
				continue;
			string var2 = type.substr(brk1+1, brk2 - brk1 - 1);
			string var3 = type.substr(brk2+1, type.size() - brk2 - 1);
			lines1.push_back({3, {var1, var2, var3}});
		}
	}

	int N2;
	cin >> N2;
	for (int i = 0; i < N2; i++) {
		string type;
		cin >> type;
		if (type == "define") {
			string variable;
			cin >> variable;
			lines2.push_back({0, {variable}});
		}
		else if (type == "read") {
			string variable;
			cin >> variable;
			lines2.push_back({1, {variable}});
		}
		else if (type == "print") {
			string variable;
			cin >> variable;
			lines2.push_back({2, {variable}});
		}
		else {
			int brk1 = 0;
			for (; type[brk1] != '='; brk1++)
				continue;
			string var1 = type.substr(0, brk1);
			int brk2 = 0;
			for (; type[brk2] != '+'; brk2++)
				continue;
			string var2 = type.substr(brk1+1, brk2 - brk1 - 1);
			string var3 = type.substr(brk2+1, type.size() - brk2 - 1);
			lines2.push_back({3, {var1, var2, var3}});
		}
	}

	if (N1 != N2) return void(cout << "NO");

	for (int i = 0; i < N1; i++) {
		if (lines1[i].first != lines2[i].first)
			return void(cout << "NO");
		if (lines1[i].first != 3) {
			if (to.find(lines1[i].second[0]) == to.end()) {
				to[lines1[i].second[0]] = lines2[i].second[0];
			}
			else {
				if (to[lines1[i].second[0]] != lines2[i].second[0]) 
					return void(cout << "NO");
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				if (to[lines1[i].second[j]] != lines2[i].second[j]) 
					return void(cout << "NO");
			}
		}
	}
	cout << "YES";
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
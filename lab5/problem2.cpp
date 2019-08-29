#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1;

vector<bool> term;
vector<vector<vector<int>>> gr;

bool ok(set<int> v, string &s, int ind) {
	// cout << v << " " << ind << endl;
	if (ind == (int)s.size()) {
		for (auto &v2 : v)
			if (term[v2])
				return true;
		return false;
	}
	set<int> to;
	for (auto v2 : v)
		for (auto &to2 : gr[v2][s[ind] - 'a'])
			to.insert(to2);
	return ok(to, s, ind + 1);
}

int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("problem2.in", "r", stdin), freopen("problem2.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	int n, m, k;
	cin >> s >> n >> m >> k;
	term.resize(n);
	for (int i = 0, t; i < k; ++i) {
		cin >> t, --t;
		term[t] = true;
	}

	gr.resize(n, vector<vector<int>> (P));
	char c;
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c, --fr, --to;
		gr[fr][c - 'a'].push_back(to);
	}

	// cout << "ok" << endl;
	cout << (ok(set<int> {0}, s, 0) ? "Accepts" : "Rejects");
	
	return 0;
}
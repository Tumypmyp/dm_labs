#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1;

vector<bool> term;
vector<vector<int>> gr;

bool ok(int v, string &s, int ind) {
	// cout << v << " " << ind << endl;
	if (v < 0)
		return false;
	if (ind == (int)s.size())
		return term[v];
	return ok(gr[v][s[ind] - 'a'], s, ind + 1);
}

int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("problem1.in", "r", stdin), freopen("problem1.out", "w", stdout);
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

	gr.resize(n, vector<int> (P, -1));
	char c;
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c, --fr, --to;
		gr[fr][c - 'a'] = to;
	}

	// cout << "ok" << endl;
	cout << (ok(0, s, 0) ? "Accepts" : "Rejects");
	
	return 0;
}

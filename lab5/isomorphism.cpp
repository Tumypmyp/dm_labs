#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1, MOD = 1e9 + 7;

vector<bool> term, term2, used;
vector<vector<int>> gr, gr2;

bool dfs(int v1, int v2) {
	// cout << v1 << " " << v2 << "\n";
	used[v1] = true;
	if (term[v1] ^ term2[v2]) {
		return false;
	}
	// cout << "ok1" << endl;
	for (int c = 'a'; c <= 'z'; ++c) {
		int to = gr[v1][c - 'a'];
		int to2 = gr2[v2][c - 'a'];
		if (to < 0 && to2 < 0)
			continue;
		// cout << to << " " << to2 << " - tos" << endl;
		if (((to < 0) ^ (to2 < 0)) || (!used[to] && !dfs(to, to2)))
			return false;
	}
	return true;
}
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("isomorphism.in", "r", stdin), freopen("isomorphism.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	term.resize(n);
	for (int i = 0, t; i < k; ++i) {
		cin >> t, --t;
		term[t] = true;
	}

	gr.resize(n, vector<int> (P, -1));
	char c;
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c, --fr, --to;
		gr[fr][c  - 'a'] = to;
	}
	
	int n2, m2, k2;
	cin >> n2 >> m2 >> k2;
	if (n != n2 || m != m2 || k != k2) {
		cout << "NO";
		return 0;
	}
	term2.resize(n);
	for (int i = 0, t; i < k; ++i) {
		cin >> t, --t;
		term2[t] = true;
	}

	gr2.resize(n, vector<int> (P, -1));
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c, --fr, --to;
		gr2[fr][c - 'a'] = to;
	}
	/*/
	for (int i = 0; i < n; ++i)
		cout << term[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; ++i)
		cout << term2[i] << " ";
	cout << "\n";
	for (auto &v : gr) {
		for (auto &to : v) {
			if (to < 0)
				continue;
			cout << to << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (auto &v : gr2) {
		for (auto &to : v) {
			if (to < 0)
				continue;
			cout << to << " ";
		}
		cout << "\n";
	}
	//*/

	used.resize(n);
	

	cout << (dfs(0, 0) ? "YES" : "NO");

	return 0;
}
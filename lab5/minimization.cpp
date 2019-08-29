#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1, MOD = 1e9 + 7;

vector<bool> term, term2, used;
vector<vector<int>> gr;
vector<vector<vector<int>>> un_gr;

void dfs(int v) {
	used[v] = true;
	for (auto &to : gr[v])
		if (!used[to])
			dfs(to);
}

int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("minimization.in", "r", stdin), freopen("minimization.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	term.resize(n + 1);
	for (int i = 0, t; i < k; ++i) {
		cin >> t, --t;
		term[t] = true;
	}

	gr.resize(n + 1, vector<int> (P));
	un_gr.resize(n + 1, vector<vector<int>> (P));
	char c;
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c;
		gr[fr][c  - 'a'] = to;
		un_gr[to][c - 'a'].push_back(fr);
	}
	
	dfs(1);

	queue<pair<int, int>> q;
	vector<vector<bool>> diff(n + 1, vector<bool> (n + 1));
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			if (term[i] ^ term[j]) {
				diff[j][i] = diff[i][j] = 1;
				q.push({i, j});
			}
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		for (char c = 'a'; c <= 'z'; ++c) {
			for (auto to : un_gr[v.first][c - 'a'])
				for (auto to2 : un_gr[v.second][c - 'a']) {
					diff[to][to2] = true;
					q.push({to, to2});
				}
		}
	}

	/*/
	for (int i = 0; i < n; ++i)
		cout << term[i] << " ";
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
	//*/
	vector<bool> term2;
	vector<vector<int>> gr2;
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; ++i) 
		if (used[i] && ans[i] == 0) {
			bool t = false;
			gr2.push_back({});
			for (int j = 0; j <= n; ++j)
				if (!diff[i][j]) {
					t |= term[j];
					ans[j] = term2.size()
					gr2.back().push_back(j);
				}
			term2.push_back(t);
		}
	vector<vector<int>> gr_ans(gr2.size(), vector<int> (P))
	for (int i = 0; i < gr_ans.size(); ++i) {
		for (char c = 'a'; c <= 'z'; ++c) {
			gr_ans[i][c - 'a'] = gr[gr2[i][0]][c - 'a'];
		}
	}
	cout << gr2.size() << " " << 
	return 0;
}
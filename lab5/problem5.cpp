#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1, MOD = 1e9 + 7;

vector<bool> term;
vector<vector<vector<int>>> gr;


int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("problem5.in", "r", stdin), freopen("problem5.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k, l;
	cin >> n >> m >> k >> l;
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

	map<set<int>, bool> used;
	map<set<int>, vector<set<int>>> gr2;
	queue<set<int>> q1;
	q1.push({0});
	used[q1.front()] = true; 
	while (!q1.empty()) {
		auto fr = q1.front();
		
		q1.pop();
		gr2[fr].resize(P);
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			set<int> to;
			for (auto &p : fr) {
				for (auto &p2 : gr[p][ch - 'a'])
					to.insert(p2);
			}
			if (!used[to]) {
				q1.push(to);
				used[to] = true;
			}
			gr2[fr][ch - 'a'] = to;
		}
	}

	/*/
	for (auto &v : gr2) {
		for (auto &p : v.first)
			cout << p << ", ";
		cout << " -> ";
		for (int i = 0; i < P; ++i) {
			auto v2 = v.second[i];
			if (v2.empty())
				continue;
			cout << ", " << char('a' + i) << "{";
			for (auto &p : v2)
				cout << p << ", ";
			cout << "}";
		}
		cout << "\n";
	}

	//*/
	map<set<int>, int> q;
	q[{0}] = 1;
	for (int i = 0; i < l; ++i) {
		/*/
		for (auto &p : q)
			cout << p.first << " " << p.second << ", ";
		cout << "\n";
		//*/
		map<set<int>, int> q2;
		for (auto &p : q)
			for (auto to : gr2[p.first]) {
				q2[to] += p.second;
				q2[to] %= MOD;
			}
		q = q2;
	}

	int ans = 0;
	for (auto &p : q) {
		bool t = false;
		for (auto &v : p.first)
			t = t || term[v];
		ans += t * p.second;
		ans %= MOD;
	}
		/*/
		for (auto &p : q)
			cout << p.first << " " << p.second << ", ";
		cout << "\n";
		//*/
	cout << ans;

	return 0;
}
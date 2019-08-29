#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1, MOD = 1e9 + 7;

vector<bool> term, term2;
vector<vector<int>> gr, gr2;

int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("equivalence.in", "r", stdin), freopen("equivalence.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	term.resize(n + 1);
	for (int i = 0, t; i < k; ++i) {
		cin >> t, --t;
		term[t] = true;
	}

	gr.resize(n + 1, vector<int> (P, n));
	char c;
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c, --fr, --to;
		gr[fr][c  - 'a'] = to;
	}
	
	int n2, m2, k2;
	cin >> n2 >> m2 >> k2;
	
	term2.resize(n2 + 1);
	for (int i = 0, t; i < k2; ++i) {
		cin >> t, --t;
		term2[t] = true;
	}

	gr2.resize(n2 + 1, vector<int> (P, n2));	
	for (int i = 0, fr, to; i < m2; ++i) {
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

	// cout << "OK" << endl;
	vector<int> used, used2;
	used.resize(n + 1);
	used2.resize(n2 + 1);
	queue<pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto v = q.front();
		used[v.x]++;
		used2[v.y]++;
		q.pop();
		// cout << v.x << " " << v.y << endl;
		if (term[v.x] ^ term2[v.y]) {
			cout << "NO";
			return 0;
		}
		for (int c = 'a'; c <= 'z'; ++c) {
			pair<int, int> to = {gr[v.x][c - 'a'], gr2[v.y][c - 'a']};
			if (used[to.x] < 10 || used2[to.y] < 10) {
				q.push(to);
			}
		}
	}	

	cout << "YES";
	return 0;
}
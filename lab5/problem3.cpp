#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1, MOD = 1e9 + 7;

vector<bool> term;
vector<vector<int>> gr;



// not working
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("problem3.in", "r", stdin), freopen("problem3.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	term.resize(n);
	for (int i = 0, t; i < k; ++i) {
		cin >> t, --t;
		term[t] = true;
	}

	gr.resize(n);
	char c;
	for (int i = 0, fr, to; i < m; ++i) {
		cin >> fr >> to >> c, --fr, --to;
		gr[fr].push_back(to);
	}

	map<int, int> q;
	q[0] = 1;
	ll ans = term[0];
	for (int i = 0; i < max(1e3, 1e6 / m); ++i) {
		/*/
		for (auto &p : q)
			cout << p.first << " " << p.second << ", ";
		cout << "\n";
		//*/
		map<int, int> q2;
		for (auto &p : q)
			for (auto to : gr[p.first]) {
				q2[to] += p.second;
				q2[to] %= MOD;
			}
		q = q2;
		for (auto &p : q) {
			ans += term[p.first] * p.second;
			ans %= MOD;
		}
	}
	ll ans2 = ans;
	for (int i = 0; i < 1e2; ++i) {
		/*/
		for (auto &p : q)
			cout << p.first << " " << p.second << ", ";
		cout << "\n";
		//*/
		map<int, int> q2;
		for (auto &p : q)
			for (auto to : gr[p.first]) {
				q2[to] += p.second;
				q2[to] %= MOD;
			}
		q = q2;
		for (auto &p : q) {
			ans2 += term[p.first] * p.second;
			ans2 %= MOD;
		}
	}
		/*/
		for (auto &p : q)
			cout << p.first << " " << p.second << ", ";
		cout << "\n";
		//*/
	cout << (ans == ans2 ? ans : -1);

	return 0;
}
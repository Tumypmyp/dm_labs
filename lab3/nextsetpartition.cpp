#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 53, P = 'z' - 'a' + 1;




vector<int> vec(string s) {
	vector<int> ans(1);
	for (auto &ch : s) {
		if (ch == ' ') {
			ans.push_back(0);
		} else {
			ans.back() *= 10;
			ans.back() += ch - '0';
		}
	}
	return ans;
}

void solve(vector<vector<int>> a, int n, int k) {
	auto b = a;
	for (auto &v : a)
		for (auto &p : v)
			p--;
	vector<bool> used(n, true);
	for (auto &p : a.back())
		used[p] = false;
	a.pop_back();

	while (true) {
		for (int j = a.empty() ? b[0][0] : max(a.back().back(), b[a.size() - 1][a.back().size()]); j < n; ++j)
			if (!used[j]) {
				if(a.empty())
					a.push_back(vector<int>());
				// for (int j2 = j; j2 < n; ++j2)
					// if (!used[j2]) {
						a.back().push_back(j);
						used[j] = true;
					// }
				// for (auto &p : a.back())
				a.push_back(vector<int>());
				for (int u = 0; u < n; ++u)
					if (!used[u])
						a.back().push_back(u);
				cout << n << " " << k << "\n";
				for (auto &v : a) {
					for (auto &p : v)
						cout << p + 1 << " ";
					cout << "\n";
				}
				cout << "\n\n\n";
				return;
			
			}
		used[a.back().back()] = false;
		a.back().pop_back();
		if (a.back().empty())
			a.pop_back();
		//*/
		for (int j = 0; j < n; ++j)
			cout << used[j] << " ";
		cout << "\n";

		for (auto &v : a) {
			for (auto &p : v)
				cout << p + 1 << " ";
			cout << "\n";
		}
		cout << endl;
		//*/
	}

}
 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("nextsetpartition.in", "r", stdin), freopen("nextsetpartition.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k;
	string s;
	while (getline(cin, s)) {
		if (s == "0 0") 
			break;
		n = vec(s)[0], k = vec(s)[1];
		vector<vector<int>> a;
		for (int i = 0; i < k; ++i) {
			getline(cin, s);
			a.push_back(vec(s));
		}
		//*/
		cout << "--\n";
		for (auto &v : a) {
			for (auto &p : v)
				cout << p << " ";
			cout << "\n";
		}
		cout << "---\n";
		//*/
		solve(a, n, k);
		getline(cin, s);
	}

	return 0;
}
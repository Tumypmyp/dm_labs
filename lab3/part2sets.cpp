#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;


void rec(vector<vector<int>> &a, int k, vector<bool> used, int n) {
	/*/
	cout << k << " " << n << "\n";
	for (auto &v : a) {
		for (auto &p : v)
			cout << p + 1 << " ";
		cout << "\n";
	}
	cout << endl;
	//*/
	if (n == 0) {
		if (k == 0) {
			for (auto &v : a) {
				for (auto &p : v)
					cout << p + 1 << " ";
				cout << "\n";
			}
			cout << "\n";
		}
		return;
	}
	if (k > 0) {
		int frst = 0;
		while (frst < used.size() && used[frst]) {
			frst++;
		}
		if (frst < used.size()) {
			a.push_back({frst});
			used[frst] = true;
			rec(a, k - 1, used, n - 1);
			a.pop_back();
			used[frst] = false;
		}	
	}

	vector<int> &v = a.back();
	for (int i = (v.empty() ? a[a.size() - 2][0] : v.back()) + 1; i < used.size(); ++i) {
		if (!used[i]) {
			v.push_back(i);
			used[i] = true;
			rec(a, k, used, n - 1);
			v.pop_back();
			used[i] = false;
		}
	}
	
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("part2sets.in", "r", stdin), freopen("part2sets.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a = {{0}};
	vector<bool> used(n);
	used[0] = true;
	rec(a, k - 1, used, n - 1);
	return 0;
}
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;


void rec(vector<int> &a, int n, vector<bool> &used) {
	if (a.size() == n) {
		for (auto &p : a)
			cout << p + 1 << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			a.push_back(i);
			used[i] = true;
			rec(a, n, used);
			a.pop_back();
			used[i] = false;
		}
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("permutations.in", "r", stdin), freopen("permutations.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	vector<bool> used(n);
	rec(a, n, used);
	return 0;
}
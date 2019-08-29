#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;


void rec(vector<int> &a, int k, vector<bool> &used) {
	if (a.size() == k) {
		for (auto &p : a)
			cout << p + 1 << " ";
		cout << "\n";
		return;
	}
	for (int i = (a.empty() ? 0 : a.back()); i < used.size(); ++i)
		if (!used[i]) {
			a.push_back(i);
			used[i] = true;
			rec(a, k, used);
			a.pop_back();
			used[i] = false;
		}
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("choose.in", "r", stdin), freopen("choose.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a;
	vector<bool> used(n);
	rec(a, k, used);
	return 0;
}
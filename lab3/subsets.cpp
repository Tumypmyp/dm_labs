#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;


void rec(vector<int> &a, int n) {
	for (auto &p : a)
		cout << p << " ";
	cout << "\n";
	for (int i = (a.empty() ? 0 : a.back()) + 1; i <= n; ++i) {
		a.push_back(i);
		rec(a, n);
		a.pop_back();
	}
	
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("subsets.in", "r", stdin), freopen("subsets.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	rec(a, n);
	return 0;
}
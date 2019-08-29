#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;


void rec(vector<int> &a, int n, int p = 0) {
	if (n == 0) {
		for (int i = 0; i < a.size(); ++i)
			cout << (i == 0 ? "" : "+") << a[i];
		cout << "\n";
		return;
	}
	for (int i = (a.empty() ? 1 : a.back()); i <= n; ++i) {
		a.push_back(i);
		rec(a, n - i);
		a.pop_back();
	}
	
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("partition.in", "r", stdin), freopen("partition.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	rec(a, n);
	return 0;
}
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;


void rec(vector<char> &a, int n, int p = 0) {
	if (a.size() == n) {
		if (p != 0)
			return;
		for (auto &p : a)
			cout << p;
		cout << "\n";
		return;
	}
	a.push_back('(');
	rec(a, n, p + 1);
	a.pop_back();
	if (p <= 0) 
		return;
	a.push_back(')');
	rec(a, n, p - 1);
	a.pop_back();
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("brackets.in", "r", stdin), freopen("brackets.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<char> a;
	rec(a, n * 2);
	return 0;
}
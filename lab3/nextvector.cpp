#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;




 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("nextvector.in", "r", stdin), freopen("nextvector.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		a[i] = s[i] - '0';

	auto b = a;
	if (b == vector<int> (n, 0)) {
		cout << "-\n";
	} else {
		for (int i = n - 1; i >= 0; --i) {
			if (b[i] == 1) {
				b[i] = 0;
				break;
			} else
				b[i] = 1;
		}
		for (auto &p : b)
			cout << p;
		cout << "\n";
	}
	b = a;
	if (b == vector<int> (n, 1)) {
		cout << "-\n";
	} else {
		for (int i = n - 1; i >= 0; --i) {
			if (b[i] == 0) {
				b[i] = 1;
				break;
			} else
				b[i] = 0;
		}
		for (auto &p : b)
			cout << p;
		cout << "\n";
	}
	return 0;
}
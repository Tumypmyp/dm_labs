#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 53, P = 'z' - 'a' + 1;



 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("nextbrackets.in", "r", stdin), freopen("nextbrackets.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<char> a;
	for (auto &ch : s)
		a.push_back(ch);

	int cl = 0, op = 0;
	for (int i = n - 1; i > 0; --i) {
		if (s[i] == '(') {
			++op;
			if (op < cl)
				break;
		} else {
			++cl;
		}
		a.pop_back();
	}
	a.pop_back();
	/*
	for (auto &p : a)
		cout << p;
	cout << "\n";
	//*/

	if (a.empty()) {
		cout << "-";
		return 0;
	}
	a.push_back(')');
	for (int i = 0; i < op; ++i)
		a.push_back('(');
	for (int i = 1; i < cl; ++i)
		a.push_back(')');

	for (auto &p : a)
		cout << p;
	return 0;
}
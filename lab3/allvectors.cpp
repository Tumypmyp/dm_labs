#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;

bool getb(int a, int ind) {
	return (a >> ind) & 1;
}

void out_mask(int a, int n, string s) {
	for (int i = 0; i < n; ++i)
		cout << getb(a, n - 1 - i);
	cout << s;
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	// #else
		// freopen("allvectors.in", "r", stdin), freopen("allvectors.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int mask = 0; mask < (1 << n); ++mask) {
		out_mask(mask, n, "\n");
	}

	return 0;
}
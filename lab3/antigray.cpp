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

int pushb(int a, int ind) {
	return a | (1 << ind);
}

void out_mask(int a, int n, string s) {
	for (int i = 0; i < n; ++i)
		cout << getb(a, n - 1 - i);
	cout << s;
}


vector<int> get_gray(int n) {
	if (n == 1) {
		return {0, 1};
	}
	vector<int> ans = get_gray(n - 1);
	for (int i = ans.size() - 1; i >= 0; --i)
		ans.push_back(pushb(ans[i], n - 1));
	return ans;
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("antigray.in", "r", stdin), freopen("antigray.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < pow(3, n - 1); ++i) {
		vector<int> k;
		int a = i;
		for (int j = 0; j < n; ++j) {
			k.push_back(a % 3);
			a /= 3;
		}
		for (int j = 0; j < 3; ++j) {
			for (auto &p : k) {
				cout << p++ % 3;
			}
			cout << "\n";
		}

	}
	return 0;
}
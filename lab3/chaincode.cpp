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


 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("chaincode.in", "r", stdin), freopen("chaincode.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	vector<vector<int>> ans;
	map<vector<int>, bool> was;
	
	ans.push_back(a);
	was[a] = true;
	while (true) {
		copy(a.begin() + 1, a.end(), a.begin());
		a.back() = 1;
		if (!was[a]) {
			ans.push_back(a);
			was[a] = true;
		} else {
			a.back() = 0;
			if (!was[a]) {
				ans.push_back(a);
				was[a] = true;		
			} else {
				break;
			}
		}
	}
	for (auto &v : ans) {
		for (auto &p : v)
			cout << p;
		cout << "\n";
	}
	return 0;
}
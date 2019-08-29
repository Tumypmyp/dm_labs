#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 53, P = 'z' - 'a' + 1;



vector<int> vec(string s) {
	vector<int> ans(1);
	for (auto &ch : s) {
		if ('0' <= ch && ch <= '9') {
			ans.back() *= 10;
			ans.back() += ch - '0';
		} else {
			ans.push_back(0);
		}
	}
	return ans;
}


 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("nextpartition.in", "r", stdin), freopen("nextpartition.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	auto a = vec(s);
	if (a.size() == 2) {
		cout << "No solution";
		return 0;
	}
	a[a.size() - 2]++;
	a[a.size() - 1]--;
	if (a[a.size() - 2] > a.back()) {
		a[a.size() - 2] += a.back();
		a.pop_back();
	} else {
		while (a[a.size() - 2] * 2 <= a.back()) {
			a.push_back(a.back() - a[a.size() - 2]);
			a[a.size() - 2] = a[a.size() - 3];
		}
	}
	for (int i = 0; i < a.size(); ++i)
		cout << (i == 0 ? "" : i == 1 ? "=" : "+") << a[i];
	return 0;
}
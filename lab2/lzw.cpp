#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 

const int P = 'z' - 'a' + 1;

int a[P];
 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("lzw.in", "r", stdin), freopen("lzw.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	map<string, int> ind;
	int ind_v = P;
	string ch = "a";
	for (int i = 0; i < P; ++i) {
		ch[0] = 'a' + i;
		ind[ch] = i;
	}

	for (int i = 0; i < s.size();) {
		string now = "";
		while (i < s.size()) {
			string new_s = now + s[i++];
			if (ind.count(new_s) > 0)
				now = now + s[i - 1];
			else {
				ind[new_s] = ind_v++;
				--i;
				break;
			}
		}
		cout << ind[now] << " ";
	}

 
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int N = 2e5 + 7;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; 
    while (t--) {
		int n; cin >> n; 
		int a[n+1];
		int first = N, last = 0;
		int cnt = 0;
		int test[N] = {0};
		int ok = N-1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			test[a[i]] = 1;
			if (a[i] != i) {
				if (a[i] == 0) cnt++;
				if (a[i] == 0 and (i == 1 || i == n)){
					ok = i;
				}
				first = min(first, i);
				last = max(last, i);
			}
		}
/*		cerr << ok << " " << test[ok] << endl;
		cerr << first << " " << last << endl;
		cerr << cnt << " " ; */
		if (first == last) {
			cout << 0 << endl;
		}

		else if (first != N and last != first) {
			int ans = last - first + 1;
			if (cnt == 1 && ok != N-1 and test[ok] == 0) {
				ans -= 1;
			}
			cout << ans << endl;
		}
		else cout << 0 << endl;
	}

	return 0;
}  
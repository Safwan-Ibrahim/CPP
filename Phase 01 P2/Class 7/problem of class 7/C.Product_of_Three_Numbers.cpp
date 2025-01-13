#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            int n2 = n/i;
            for (int j = i+1; j*j < n2; j++) {
                if (n2 % j == 0) {
                    cout << "YES\n";
                    cout << i << " " << j << " " << n2/j << endl;
                    return;
                } 
            }
            break;
        }
    }
    cout << "NO\n";
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
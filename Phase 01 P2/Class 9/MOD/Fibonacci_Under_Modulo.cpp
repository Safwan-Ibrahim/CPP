#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 998244353;

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ans = 1;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        ans = a + b; ans %= M;
        a = b;
        b = ans;
    }
    cout << ans << endl;
    
    return 0;
} 
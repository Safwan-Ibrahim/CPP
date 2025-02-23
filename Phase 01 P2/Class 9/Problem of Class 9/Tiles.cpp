#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 998244353;

int32_t main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    int ans = 1;
    
    for (int i = 1; i <= a + b; i++) {
        ans = 1LL * ans * 2 % M;
    }

    cout << ans << endl;
    return 0;
} 
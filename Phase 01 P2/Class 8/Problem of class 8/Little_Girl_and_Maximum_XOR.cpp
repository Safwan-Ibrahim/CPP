#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b; cin >> a >> b;
    int st = 64 - __builtin_clzl(b) - 1;
    for (int i = st; i >= 0; i--) {
        if (((b >> i) & 1) && !((a >> i) & 1)) {
            cout << (1LL << (i + 1)) - 1 << endl; return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
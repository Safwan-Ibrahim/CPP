#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
bitset<4002> a[N],b[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = a[i - 1];
        a[i].flip(x);
    }

    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        b[i] = b[i - 1];
        b[i].flip(x);
    }

    while(q--) {
        int l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
        bitset<4002>bs = ((a[r1] ^ a[l1 - 1]) ^ (b[r2] ^ b[l2 - 1]));
        cout << bs.count() << endl;
    }
    return 0;
} 
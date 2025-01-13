#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int a[1005][1005],dif[1005][1005];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }

    int q; cin >> q;
    while(q--) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        dif[x1][y1] += 1;
        dif[x1][y2+1] -= 1;
        dif[x2+1][y1] -= 1;
        dif[x2+1][y2+1] += 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dif[i][j] = dif[i][j]+dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
            if (dif[i][j] & 1) {
                a[i][j] ^= 1;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
} 
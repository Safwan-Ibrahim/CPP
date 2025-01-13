// Created on: 2024-10-02 09:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int ps[11][103][103], a[103][103];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q,c; cin >> n >> q >> c;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            a[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        int x,y,s; cin >> x >> y >> s;
        a[x][y] = s;
    }

    int mod = c+1;

    for (int i = 0; i <= c; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                int x = (a[j][k] != -1 ? (a[j][k]+i)%mod : 0);
                ps[i][j][k] = ps[i][j-1][k]+ps[i][j][k-1]+x-ps[i][j-1][k-1];
            }
        }
    }

    while(q--) {
        int t,x1,y1,x2,y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= mod; 
        cout << ps[t][x2][y2] - ps[t][x1-1][y2] - (ps[t][x2][y1-1]-ps[t][x1-1][y1-1]) << endl;
    }
    
    return 0;
} 
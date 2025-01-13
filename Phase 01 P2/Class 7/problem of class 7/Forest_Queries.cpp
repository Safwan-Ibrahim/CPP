#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
int arr[N][N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q; cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '*') {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] += arr[i][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[j][i] += arr[j-1][i];
        }
    }

    while(q--) {
        int lr,lc,rr,rc; cin >> lr >> lc >> rr >> rc;
        cout << arr[rr][rc] - arr[lr-1][rc] - (arr[rr][lc-1]-arr[lr-1][lc-1]) << endl;
    }

    return 0; 
} 
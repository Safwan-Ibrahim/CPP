#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int arr[1005][1005];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m; // n = 3, m = 4

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] += arr[i][j-1];
            //cout << arr[i][j] << " ";
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            arr[j][i] += arr[j-1][i]; 
        }
    }

    int lr = 2, lc = 2, rr = 3, rc = 4;

    cout << (arr[rr][rc] - arr[lr-1][rc]) - (arr[rr][lc-1] - arr[lr-1][lc-1]) << endl;
    
    return 0;
} 
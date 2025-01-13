#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    int arr[n+1], brr[m+1];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> brr[i];
    }

    int p1 = 1, p2 = 1;;

    for (int i = 1; i <= n+m; i++) {
        if (p1 > n) {
            cout << brr[p2++] << " ";
        }
        else if (p2 > m) {
            cout << arr[p1++] << " ";
        }
        else if (arr[p1] < brr[p2]) {
            cout << arr[p1++] << " ";
        }
        else {
            cout << brr[p2++] << " ";
        }
    }

    cout << endl;
    
    return 0;
} 
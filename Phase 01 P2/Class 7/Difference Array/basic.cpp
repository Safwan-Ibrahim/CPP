#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+7;
int arr[N],dif[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dif[i] = arr[i]-arr[i-1];
    }

    int q; cin >> q;
    while(q--) {
        int l,r,x; cin >> l >> r >> x;
        dif[l] += x;
        dif[r+1] -= x;
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i-1] + dif[i]; 
        cout << arr[i] << " ";
    }

    return 0;
} 
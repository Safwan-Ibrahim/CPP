#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int arr[n+1];
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (n == 1 || n == 2) {
        cout << -1 << endl;
        return;
    }

    ll total = 0;
    for (int i = 1; i <= n; i++) {
        total += arr[i];
    }

    sort(arr+1,arr+n+1);

    int chosen = arr[n/2+1]*2;
    ll need = 1LL*chosen*n+1;
    cout << max(1LL*0,need-total) << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
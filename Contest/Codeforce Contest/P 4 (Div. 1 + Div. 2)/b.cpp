#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int arr[n+1],ans[n+1];
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
    }
    
    ans[n] = arr[n], ans[1] = arr[2];

    for (int i = 2; i < n; i++) {
        ans[i] = (arr[i]|arr[i+1]);
    }

    bool pos = true;
    for (int i = 1; i < n; i++) {
        if ((ans[i]&ans[i+1]) != arr[i+1]) {
            pos = false;
            break;
        }
    }
    
    if (pos) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
    }
    else {
        cout << -1;
    }
    cout << endl;

}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
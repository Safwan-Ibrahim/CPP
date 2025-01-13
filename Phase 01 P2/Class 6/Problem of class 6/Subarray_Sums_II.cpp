#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n >> x;
    int arr[n+1];
    map<ll,int>ps;

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
        ps[sum]++;
    }

    sum = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ps[x+sum];
        sum += arr[i];
        ps[sum]--;
    }
    
    cout << ans << endl;

    return 0;
} 
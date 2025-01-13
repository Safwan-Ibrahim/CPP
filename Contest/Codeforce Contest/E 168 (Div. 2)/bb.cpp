#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;
    int bad = n-k;
    ll ans = (1LL*n*(n+1))/2-((1LL*bad*(bad+1))/2);
    cout << (ans%2 == 0 ? "YES\n" : "NO\n");
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
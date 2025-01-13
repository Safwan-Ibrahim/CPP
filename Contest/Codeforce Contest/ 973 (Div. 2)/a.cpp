#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    
    int n,x,y; cin >> n >> x >> y;
    if (x > y) {
        swap(x,y);
    }
    cout << (n == 0 ? 0 : (n+x-1)/x) << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    ll n; cin >> n;

    for (int i = 1; 1LL*i*i <= n; i++) {
        if (n%i == 0 && i != 1 || n == 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
    return 0;
} 
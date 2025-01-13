#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; int k; cin >> n >> k;
    vector<ll>v1,v2;
    for (int i = 1; 1LL*i*i <= n; i++) {
        if (n%i == 0) {
            v1.push_back(i);
            if (n/i != i) {
                v2.push_back(n/i);
            }
        }
    }

    reverse(v2.begin(),v2.end());

    if (k <= v1.size()) {
        cout << v1[k-1];
    }
    else if (k <= v1.size()+v2.size()) {
        cout << v2[k-v1.size()-1];
    }
    else {
        cout << -1;
    }

    cout << endl;

    return 0;
} 
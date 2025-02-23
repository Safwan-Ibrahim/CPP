#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int a[n + 1];

    map<int,int>mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int need = k - a[i] - a[j];
            if (mp.find(need) != mp.end()) {
                if (mp[need] != i and mp[need] != j) {
                    cout << i << " " << j << " " << mp[need] << endl;
                    return 0;
                }
            }
        }   
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
} 
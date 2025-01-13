#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct distinct {

    map<int,int>mp;
    int find(int x) {
        if (mp.find(x) != mp.end()) {
            return x;
        }
        else {
            return -1;
        }
    }
    void add(int x) {
        mp[x]++;
    }
    void remove(int x) {
        mp[x]--;
        if (mp[x] == 0) {
            mp.erase(x);
        }
    }
    int size() {
        return mp.size();
    }
};

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin >> n >> k;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int r = 1; ll ans = 0;
    distinct ds;

    for (int i = 1; i <= n; i++) {
        while(r <= n && ds.size() <= k) {
            ds.add(a[r]);
            if (ds.size() > k) {
                ds.remove(a[r]);
                break;
            }
            else {
                r++;
            }
        }
        ans += r-i;
        ds.remove(a[i]);
    }

    cout << ans << endl;
    
    return 0;
} 
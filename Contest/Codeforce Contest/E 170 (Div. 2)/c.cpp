// Created on: 2024-10-14 20:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5;

void solve()
{
    int n,x; cin >> n >> x;
    int a[n + 1]; a[0] = - 5;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    vector<int>mp[N];
    int j = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1] && a[i] != a[i - 1] + 1) {
            j++;
        }
        mp[j].push_back(a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= j; i++) {
        int dis = 1, cnt = 0;
        map<int,int>t;
        for (int k = 0; k < mp[i].size(); k++) {
            t[mp[i][k]]++;
            if (k > 0) {
                if (mp[i][k] != mp[i][k-1]) {
                    dis++;
                }
            }
            if (dis > x) {
                dis--;
                ans = max(ans,cnt);
                cnt -= t.begin()->second ;
                cnt++;
                //cout << cnt << "--c\n";
                t.erase(t.begin());
            }
            else {
                cnt++;
            }
            if (k == mp[i].size() - 1 && dis <= x) {
                ans = max(ans,cnt);
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
 
void solve()
{
    int n; cin >>  n;
    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int>v;
    int k = 40;
    bool possible = false;
    while(k--) {
        int maxi = -1, mini = 1e9+9;
        for (int i = 1; i <= n; i++) {
            maxi = max(arr[i],maxi);
            mini = min(arr[i],mini);
        }
        if(mini == maxi) {
            v.push_back(maxi);
            possible = true;
            break;
        }
        else {
            int av = (mini+maxi)/2;
            v.push_back(av);
            for (int i = 1; i <= n; i++) {
                arr[i] = abs(arr[i]-av);
            }
        }
    }
    if (possible) {
        cout << v.size() << endl;
        for (auto x : v) {
            cout << x << " ";
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
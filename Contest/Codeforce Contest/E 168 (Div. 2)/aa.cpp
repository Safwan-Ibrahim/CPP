#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;
    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int cnt = 0, gold = 0;

    for (int i = 1; i <= n; i++) {
        if (arr[i] >= k) {
            gold+= arr[i];
        }
        else if (arr[i] == 0) {
            if (gold) {
                gold--;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
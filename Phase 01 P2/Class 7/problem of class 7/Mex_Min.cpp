#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e6+9;
int need = 0,ans = 1e9,mp[N];
bool done = 0;

void track() {
    if (!done) {
        for (int i = 0; i < N; i++) {
            if (mp[i] == 0) {
                ans = i;
                done = 1; return;
            }
        }
    }
    if (mp[need] == 0) {
        ans = min(need,ans);
    }
    return ;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;

    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] <= N) {
            mp[a[i]]++;
        }
        if (i >= m) {
            track();
            if (a[i-m+1] <= N) {
                mp[a[i-m+1]]--;
                need = a[i-m+1];
            }
        }
    }

    cout << ans << endl;
    
    return 0;
} 
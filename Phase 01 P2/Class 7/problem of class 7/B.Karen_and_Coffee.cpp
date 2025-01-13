#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+7;
int dd[N];
vector<int>cnt;

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,q; cin >> n >> k >> q;

    for (int i = 1; i <= n; i++) {
        int l,r; cin >> l >> r;
        dd[l]++;
        dd[r+1]--;
    }

    for (int i = 1; i <= N-2; i++) {
        dd[i] += dd[i-1];
        if (dd[i] >= k) {
            cnt.push_back(i);
        }
    }

    while(q--) {
        int l,r; cin >> l >> r;
        cout << upper_bound(cnt.begin(),cnt.end(),r) - lower_bound(cnt.begin(),cnt.end(),l) << endl;
    }

    return 0;
} 
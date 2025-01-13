#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e7 + 9;
int spf[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int>ans;
        while(n > 1) {
            ans.push_back(spf[n]);
            n /= spf[n];
        }
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
} 
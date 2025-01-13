#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int mask[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        vector<int>freq(26,0);
        for (auto x : s) {
            freq[x - 'a']++;
        }

        for (int k = 0; k < 26; k++) {
            if(freq[k] & 1) {
                mask[i] += 1 << k;
            }
        }
    }

    ll ans = 0;
    map<int,int> cnt;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 26; k++) {
            ans += cnt[mask[i] ^ (1 << k)];
        }
        ans += cnt[mask[i]]++;
    }

    cout << ans << endl; 
    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
vector<int>Add[N],Rem[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);  
    cin.tie(0);

    int n,q; cin >> n >> q;

    for (int i = 1; i <= q; i++) {
        int l,r,x; cin >> l >> r >> x;
        Add[l].push_back(x);
        Rem[r + 1].push_back(x);
    }

    map<int,int>mp;
    for (int i = 1; i <= n; i++) {
        for (auto x : Add[i]) {
            mp[x]++;
        }

        for (auto x : Rem[i]) {
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        }
        cout << mp.size() << endl;
    }

    return 0;
} 
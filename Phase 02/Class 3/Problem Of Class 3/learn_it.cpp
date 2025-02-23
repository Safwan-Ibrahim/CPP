#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int MAXN = 50005;

int L[MAXN], R[MAXN], Q[MAXN];

void solve() {
    int n, q; 
    cin >> n >> q;
    
    vector<int> points;
    
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        points.push_back(L[i]);
        points.push_back(R[i] + 1);
    }
    
    for (int i = 1; i <= q; i++) {
        cin >> Q[i];
        points.push_back(Q[i]);
    }
    
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    
    map<int, int> Dif;
    
    for (int i = 1; i <= n; i++) {
        Dif[L[i]]++;
        Dif[R[i] + 1]--;
    }
    
    int cnt = 0;
    for (int x : points) {
        cnt += Dif[x];
        Dif[x] = cnt;
    }

    for (int i = 1; i <= q; i++) {
        cout << Dif[Q[i]] << endl;
    }    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}

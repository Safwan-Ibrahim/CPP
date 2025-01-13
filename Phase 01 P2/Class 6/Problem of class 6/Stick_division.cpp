#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x,n; cin >> x >> n;
    priority_queue<int,vector<int>,greater<int>>pq;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pq.push(a);
    }

    ll ans = 0;

    while(pq.top() != x) {
        int prev_length = pq.top();
        pq.pop();
        prev_length += pq.top();
        pq.pop();
        pq.push(prev_length);
        ans += prev_length;
    }

    cout << ans << endl;

    return 0;
} 
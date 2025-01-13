#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
int a[N],l[N],r[N],x[N];
ll op[N],dif[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0); // font of comment I want to change 
    cin.tie(0);

    int n,m,k; cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dif[i] =  a[i]-a[i-1];
    }

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> x[i];
    }

    for (int i = 1; i <= k; i++) {
        int x,y; cin >> x >> y;
        op[x]++;
        op[y+1]--;
    }

    for (int i = 1; i <= m; i++) {
        op[i] += op[i-1];
    }

    for (int i = 1; i <= m; i++) {
        dif[l[i]] += x[i]*op[i];
        dif[r[i]+1] -= x[i]*op[i];
    }

    for (int i = 1; i <= n; i++) {
        dif[i] += dif[i-1];
        cout << dif[i] << " ";
    }

    cout << endl;

    return 0;
} 
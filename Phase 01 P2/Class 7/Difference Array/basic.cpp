#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+7;
int A[N], Dif[N];

int32_t main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        Dif[i] = A[i] - A[i - 1];
    }

    int q; cin >> q;
    while(q--) {
        int l,r,x; cin >> l >> r >> x;
        Dif[l] += x;
        Dif[r + 1] -= x;
    }

    for (int i = 1; i <= n; i++) {
        A[i] = A[i - 1] + Dif[i]; 
        cout << A[i] << " ";
    }

    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
int A[N];

int32_t main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; ll s; cin >> n >> s;
    for (int i = 1; i <= n; i++) { 
        cin >> A[i]; 
    }

    ll sum = 0;
    int r = 1;
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        while(r <= n && A[r] + sum <= s) {
            sum += A[r];
            r++;
        }
        ans = max(ans, r - l); 
        sum -= A[l];
    }

    cout << ans << endl;

    return 0;
} 
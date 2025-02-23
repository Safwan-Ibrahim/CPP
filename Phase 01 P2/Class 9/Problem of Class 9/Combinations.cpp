#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 1000003, N = 1e6 + 2;
int fact[N], ifact[N];

int power(int x, int n) {
    int ans = 1;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * x * ans % M;
        }
        x = 1LL * x * x % M;
        n >>= 1;
    }
    return ans;
}

int inverse(int x) {
    return power(x, M - 2);
}

void prec() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % M;
    }

    ifact[N - 1] = inverse(fact[N - 1]);

    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % M;
    }
}

int C(int n, int r) {
    if (r > n || r < 0 || n < 0) {
        return 0;
    }
    return 1LL * fact[n] * ifact[r] % M * ifact[n - r] % M;
    //return 1LL * fact[n] * inverse(fact[r]) % M * inverse(fact[n - r]) % M; 
}

int P(int n, int r) {
    if (r > n || r < 0 || n < 0) {
        return 0;
    }
    return 1LL * fact[n] * ifact[n - r] % M;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    int q; cin >> q;
    int c = 0;
    while(q--) {
        int n,r; cin >> n >> r;
        cout << "Case " << ++c << ": "; 
        cout << C(n,r) << endl;
    }
    
    return 0;
} 
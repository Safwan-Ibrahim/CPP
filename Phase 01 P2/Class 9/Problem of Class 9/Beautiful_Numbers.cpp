#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9, M = 1000000007;
int fact[N], ifact[N];

bool is_good(int x, int a, int b) {
    while(x) {
        int d = x % 10;
        if (d != a && d != b) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        x = 1LL * x * x % m;
        n >>= 1;
    }
    return ans;
}

void prec() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * i * fact[i - 1] % M;
    }

    for (int i = 0; i < N; i++) {
        ifact[i] = power(fact[i], M - 2, M);
    }
    return;
}

int nCk(int n, int k) {
    int up = fact[n];
    int down = 1LL * ifact[n - k] * ifact[k] % M;
    return 1LL * up * down % M;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); prec();

    int a, b, n; cin >> a >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int sum = a * i + (n - i) * b;
        if (is_good(sum, a, b)) {
            ans = (nCk(n, i) + ans) % M;
        }
    }
    cout << ans << endl;
    
    return 0;
} 
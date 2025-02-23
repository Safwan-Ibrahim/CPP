#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N =1e5 + 9, M = 998244353;
int fact[N];

void prec() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % M;
    }
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); prec();

    int n; cin >> n; cout << fact[n] << endl;
    
    return 0;
} 
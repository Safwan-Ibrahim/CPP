// Created on: 2025-04-06 16:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 505, M = 1e9 + 7;
int n, need, Ans[N][N * N];


int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

int way(int i, int sum) {
    if (i == n + 1) {
        return sum == need;
    }
    int &ans = Ans[i][sum];
    if (ans != -1) {
        return ans;
    }
    ans = way(i + 1, sum);
    if (sum + i <= need) {
        ans += way(i + 1, sum + i);
    }
    ans %= M;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    int sum = n * (n + 1) / 2;
    int ans = 0;
    if (sum % 2 == 0) {
        need = sum / 2;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= need; j++) {
                Ans[i][j] = -1;
            }
        }
        ans = way(1, 0);
        ans = 1LL * ans * power(2, M - 2, M) % M;
    }

    cout << ans << endl;
    
    return 0;
} 
// Created on: 2025-07-15 21:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 107;
int n, A[nn], need, Ans[nn][200007];

bool pos(int i, int sum) {
    if (i == n + 1) return sum == need;
    int &ans = Ans[i][sum];
    if (ans != -1) return ans;
    ans = pos(i + 1, sum + A[i]);
    ans |= pos(i + 1, sum);
    return ans;
}

void reset() {
    memset(Ans, -1, sizeof Ans);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
    }

    reset();
    need = sum / 2;
    if (sum % 2 == 1 || !pos(1, 0)) {
        cout << 0 << endl; return 0;
    }

    for (int i = 2; ;i *= 2) {
        for (int j = 1; j <= n; j++) {
            if (A[j] % i) {
                reset();
                need = sum - A[j] / 2;
                A[j] = 0;
                assert(!pos(1, 0));
                cout << 1 << "\n" << j << endl; return 0;
            }
        }
    }
    
    
    return 0;
} 
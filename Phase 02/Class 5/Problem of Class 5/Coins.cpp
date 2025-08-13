// Created on: 2025-03-29 02:13
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e3 + 8;
double A[nn], Ans[nn][nn];
bool Vs[nn][nn];
int n;

double pro(int i, int head) {
    if (i == n + 1) {
        int tail = n - head;
        if (head > tail) {
            return 1;
        }
        return 0;
    }
    double &ans = Ans[i][head];
    if (Vs[i][head]) {
        return ans;
    }
    ans = 0;
    ans = A[i] * pro(i + 1, head + 1);
    ans += (1 - A[i]) * pro(i + 1, head);
    Vs[i][head] = true;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    memset(Vs, 0, sizeof Vs);
    cout << fixed << setprecision(10) << pro(1, 0) << endl;
    
    return 0;
} 
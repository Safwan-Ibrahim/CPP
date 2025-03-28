// Created on: 2025-03-25 01:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int n, A[3][N], Ans[4][N];

int max_happy(int i, int last) {
    if (i == n + 1) {
        return 0;
    }
    if (Ans[last][i] != -1) {
        return Ans[last][i];
    }
    int mx = -1;
    for (int k = 0; k < 3; k++) {
        if (k == last) {
            continue;
        }
        mx = max(mx, A[k][i] + max_happy(i + 1, k));
    }
    return Ans[last][i] = mx;
}

int max_happy_iterative() {
    vector<int>Cur_max(3, 0), Prev_max(3, 0);
    for (int i = 0; i < 3; i++) {
        Cur_max[i] = A[i][n];
    }

    for (int i = n; i >= 2; i--) {
        Prev_max[0] = (A[0][i - 1] + max(Cur_max[1], Cur_max[2]));
        Prev_max[1] = (A[1][i - 1] + max(Cur_max[0], Cur_max[2]));
        Prev_max[2] = (A[2][i - 1] + max(Cur_max[1], Cur_max[0]));
        Cur_max[0] = Prev_max[0];
        Cur_max[1] = Prev_max[1];
        Cur_max[2] = Prev_max[2];
    }

    return *max_element(Cur_max.begin(), Cur_max.end());
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> A[0][i] >> A[1][i] >> A[2][i];
    }  

    memset(Ans, -1, sizeof Ans);
    cout << max_happy(1, 3);
    //cout << max_happy_iterative() << endl;

    return 0;
} 
// Created on: 2025-07-10 18:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1007;
int n, m, A[nn], B[nn];
vector<vector<int>>Lcs(nn + 3, vector<int>(nn + 3, 0));

void print_path(int i, int j) {
    if (i > n || j > m) return;
    if (A[i] == B[j]) {
        cout << A[i] << " ";
        print_path(i + 1, j + 1); return;
    }
    int a = Lcs[i + 1][j], b = Lcs[i][j + 1];
    if (a >= b) print_path(i + 1, j);
    else print_path(i, j + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (A[i] == B[j]) Lcs[i][j] = 1 + Lcs[i + 1][j + 1];
            else Lcs[i][j] = max(Lcs[i][j + 1], Lcs[i + 1][j]);
        }
    }
    
    cout << Lcs[1][1] << endl;
    print_path(1, 1);
    
    return 0;
} 

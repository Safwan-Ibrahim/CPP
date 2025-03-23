// Created on: 2025-03-20 15:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define endl '\n'

const int N = 508;
int n, A[N][N];
bool Vs[N][N];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i][i];
    }
    
    for (int i = 1; i <= n; i++) {
        pair<int, int> cur = {i, i};
        Vs[cur.f][cur.s] = true;
        for (int j = 1; j <= A[i][i] - 1; j++) {
            if (cur.s - 1 >= 1 && !Vs[cur.f][cur.s - 1]) {
                Vs[cur.f][cur.s] = true;
                cur = {cur.f, cur.s - 1};
                A[cur.f][cur.s] = A[i][i];
            }
            else {
                Vs[cur.f + 1][cur.s] = true;
                cur = {cur.f + 1, cur.s};
                A[cur.f][cur.s] = A[i][i];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << A[i][j] << " ";
            Vs[i][j] = false;
        }
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; 
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 
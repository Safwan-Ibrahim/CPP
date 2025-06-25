// Created on: 2025-04-21 17:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define f first 
#define s second

const int nn = 2e5 + 8;
int n, Pos_first[nn];
pair<int, int>A[nn];
vector<pair<int, int>>Ans;

void go(int i, int j) {
    if (i == j) {
        return;
    }
    Ans.push_back({i, j});
    swap(A[i], A[j]);
    Pos_first[A[i].f] = i;
    Pos_first[A[j].f] = j;
    return;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i].f = x;
        Pos_first[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i].s;
    }
    
    int same = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i].f == A[i].s) {
            if (n % 2 == 0 || same > 0) {
                cout << -1 << endl; return;
            }  
            same = i;
        }
        else {
            int id = Pos_first[A[i].s];
            if (A[i].f != A[id].s) {
                cout << -1 << endl; return;
            }
        }
    }

    if (n % 2 == 1) {
        go(same, (n + 1) / 2);
    } 

    for (int i = 1; i <= n / 2; i++) {
        go(Pos_first[A[i].s], n - i + 1);
    }

    cout << Ans.size() << endl;
    for (auto [x, y] : Ans) {
        cout << x << " " << y << endl;
    }

    Ans.clear();

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 
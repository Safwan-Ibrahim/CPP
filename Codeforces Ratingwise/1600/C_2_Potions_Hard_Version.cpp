// Created on: 2025-03-16 22:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 200008; // rem to change
int pn, A[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> pn;
    for (int i = 1; i <= pn; i++) {
        cin >> A[i];
    }

    ll health = 0;
    int ans = 0;
    priority_queue<int>Pq;
    for (int i = 1; i <= pn; i++) {
        if (A[i] >= 0) {
            ans++;
            health += A[i];
        }
        else if (health + A[i] >= 0) {
            health += A[i];
            Pq.push(-A[i]);
            ans++;
        }
        else {
            if (!Pq.empty() && Pq.top() > -A[i]) {
                health += Pq.top();
                Pq.pop();
                Pq.push(-A[i]);
                health += A[i];
            } 
        }
    }

    cout << ans << endl;
    
    return 0;
} 
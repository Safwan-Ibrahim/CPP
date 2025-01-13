#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,m,rb,cb,rd,cd; 
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int op = 0;
    int dr = 1, dc = 1;

    while(rb != rd and cb != cd) {
        if (rb == n) {
            dr = -1;
        }
        if (rb == 1) {
            dr = 1;
        }
        if (cb == m) {
            dc = -1;
        }
        if (cb == 1) {
            dc = 1;
        }
        rb += dr;
        cb += dc;
        op++;
    }
    cout << op << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
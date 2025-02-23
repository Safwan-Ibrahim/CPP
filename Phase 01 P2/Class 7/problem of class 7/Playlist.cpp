// Created on: 2025-02-14 15:48
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    set<int>St;
    int mx = -1;
    int r = 1;
    for (int l = 1; l <= n; l++) {
        while(r <= n && St.find(A[r]) == St.end()) {
            St.insert(A[r]);
            r++;
        }
        mx = max(mx, r - l);
        St.erase(A[l]);
    }
    
    cout << mx << endl;
    
    return 0;
} 







// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'

// int32_t main()
// {   
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n; cin >> n;
//     int a[n+1];

//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     set<int>st;
//     int r = 1, ans = 0;
//     for (int l = 1; l <= n; l++) {
//         while(st.find(a[r]) == st.end() && r <= n) {
//             st.insert(a[r++]);
//         }
//         ans = max(ans,r-l);
//         st.erase(a[l]);
//     }
//     cout << ans << endl;

//     return 0;
// } 
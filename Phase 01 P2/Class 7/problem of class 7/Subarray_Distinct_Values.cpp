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
    
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    map<int, int>Mp;
    ll ans = 0;
    int r = 1;
    for (int l = 1; l <= n; l++) {
        while(r <= n) {
            if (Mp.size() < k || Mp.size() == k && Mp.find(A[r]) != Mp.end()) {
                Mp[A[r]]++;
                r++;
            }
            else {
                break;
            }
        }
        ans += r - l;
        Mp[A[l]]--;
        if (Mp[A[l]] == 0) {
            Mp.erase(A[l]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
} 


// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'

// struct distinct {

//     map<int,int>mp;
//     int find(int x) {
//         if (mp.find(x) != mp.end()) {
//             return x;
//         }
//         else {
//             return -1;
//         }
//     }
//     void add(int x) {
//         mp[x]++;
//     }
//     void remove(int x) {
//         mp[x]--;
//         if (mp[x] == 0) {
//             mp.erase(x);
//         }
//     }
//     int size() {
//         return mp.size();
//     }
// };

// int32_t main()
// {   
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n,k; cin >> n >> k;
//     int a[n+1];

//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     int r = 1; ll ans = 0;
//     distinct ds;

//     for (int i = 1; i <= n; i++) {
//         while(r <= n && ds.size() <= k) {
//             ds.add(a[r]);
//             if (ds.size() > k) {
//                 ds.remove(a[r]);
//                 break;
//             }
//             else {
//                 r++;
//             }
//         }
//         ans += r-i;
//         ds.remove(a[i]);
//     }

//     cout << ans << endl;
    
//     return 0;
// } 
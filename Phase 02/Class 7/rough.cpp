#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> a({100, 9, 10, 10, 9});
    vector<int> v = a;
    sort(v.begin(), v.end());
    // [9, 9, 10, 10, 100]
    
    v.resize(unique(v.begin(), v.end()) - v.begin());
    // unique -> [9, 10, 100, 9, 10]
    // v.resize(3) -> [9, 10, 100]
    for (int i = 0; i < a.size(); i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        cout << a[i] << ' ';
    }

    // v[a[i] - 1] is the original value of a[i]
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x; cin >> n >> x;;
    multiset<int>ms;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ms.insert(a);
    }

    int box = 1;
    int filled = 0;
    int cnt = 0;

    while(!ms.empty()) {
        auto it = ms.upper_bound(x-filled);
        if (it != ms.begin()) {
            if (cnt == 2) {
                box++;
                cnt = 0;
                filled = 0;
            }
            it--;
            filled += *it;
            cnt++;
            ms.erase(it);
        }
        else {
            box++;
            filled = 0;
            cnt = 0;
        }
    }

    cout << box << endl;
    
    return 0;
} 
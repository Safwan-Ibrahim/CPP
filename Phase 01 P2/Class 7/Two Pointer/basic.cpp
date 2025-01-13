#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
int arr[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; ll s; cin >> n >> s;

    for (int i = 1; i <= n; i++) { 
        cin >> arr[i]; 
    }

    int r = 1, ans = 0;
    ll sum = 0;

    for (int l = 1; l <= n; l++) {
        sum += arr[r++];
        if (sum <= s && r <= n) {
            ans = max(ans,r-l); // r = 3 and l = 1, ans would be (3-1)+1 = 3 but we already increased by one 
        }
        else {
            sum -= arr[l];
        }
    }

    cout << ans << endl;

    return 0;
} 
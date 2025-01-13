#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool cmp(string a, string b) {
    return a+b < b+a;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string arr[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr+1,arr+n+1,cmp);

    for (int i = 1; i <= n; i++) {
        cout << arr[i];
    }

    cout << endl;
    
    return 0;
} 
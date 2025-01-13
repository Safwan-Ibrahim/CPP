#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+9;
int n,arr[N],brr[N];

ll inversions(int l, int r) 
{
    if (l >= r) {
        return 0;
    }

    ll cnt = 0;

    int mid = (l+r)/2;
    cnt += inversions(l,mid);
    cnt += inversions(mid+1,r);

    int pointer = mid+1;
    for (int i = l; i <= mid; i++) {
        while(pointer <= r && arr[pointer] < arr[i]) {
            pointer++;
        }
        cnt += pointer-(mid+1);
    }
    
    int p1 = l, p2 = mid+1;
    for (int i = l; i <= r; i++) {
        if (p1 > mid) {
            brr[i] = arr[p2++];
        }
        else if (p2 > r) {
            brr[i] = arr[p1++];
        }
        else if (arr[p1] < arr[p2]) {
            brr[i] = arr[p1++];
        }
        else {
            brr[i] = arr[p2++];
        }
    }

    for (int i = l; i <= r; i++) {
        arr[i] = brr[i];
    }

    return cnt;

}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << inversions(1,n) << endl;
}


int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
} 
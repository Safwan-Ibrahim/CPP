// Created on: 2025-02-05 01:23
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void swp(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
}

int32_t main() {
    
    int a, b; scanf("%d%d",&a,&b);
    swp(&a, &b);

    return 0;
} 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

ll n, k;
bool pred(ll num){
    ll sum = ((num * (num + 1)) / 2);
    return sum - (n - num) >= k;
}

int main() {
    cin >> n >> k;

    ll start = 0, end = 1e9, mid, ans = 0;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(pred(mid)){
            ans = mid;
            end = mid - 1;
        }else
            start = mid + 1;
    }
    cout << n - ans;
    return 0;
}

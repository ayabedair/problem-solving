#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

ll k, n;
bool pred(ll v){
    ll i = 0, x = 1, lines = 0;
    while(x){
        x = v / pow(k, i);
        lines += x;
        i++;
    }
    return lines >= n;
}

int main() {
    cin >> n >> k;

    ll start = 0, end = 1e9, mid, ans;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(pred(mid)){
            ans = mid;
            end = mid - 1;
        }else
            start = mid + 1;
    }
    cout << ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

bool pred(vector<ll>& v, ll time, ll t) {
    ull products = 0;
    for (ll i = 0; i < v.size(); ++i) {
        products += time / v[i];
        if(products >= t) break; //to avoid overflow
    }
    return products >= t;
}

int main() {
    ll n, t;
    cin >> n >> t;

    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll start = 0, end = *max_element(v.begin(), v.end()) * t, mid, ans = 0;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (pred(v, mid, t)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << ans << ln;
    return 0;
}

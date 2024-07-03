#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

#define loop(n)          for(ll i = 0; i < (n); i++)
#define lp(x, s, e)      for(ll x = (s); x < (e); x++)
#define loopj(n)         for(ll j = 0; j < (n); j++)
#define space " "


int main() {
    int n; cin >> n;
    vector<int>v(n), val(n);
    loop(n) cin >> v[i];
    sort(v.begin(), v.end());

    ll res = 0;
    loop(n) {
        int start = i, end = n - 1;
        ll maxx = v[i] + 5;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] <= maxx)
                start = ++mid;
            else
                end = --mid;
            res = max(res, start - i);
        }
    }

    cout << res;

    return 0;
}

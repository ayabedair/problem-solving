#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

#define loop(n)          for(ll i = 0; i < (n); i++)
#define lp(x, s, e)      for(ll x = (s); x < (e); x++)
#define loopj(n)         for(ll j = 0; j < (n); j++)
#define space " "



int main() {

    int n, x; cin >> n >> x;
    vector<pair<int, int>>v(n);
    loop(n) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n ; ++i){
        for(int j = i + 1; j < n ; ++j){
                int start = j + 1 , end = n - 1;
                while(start < end){
                    ll sum = v[i].first + v[j].first + v[start].first + v[end].first;
                    if(sum == x){
                        cout << v[i].second << space << v[j].second << space << v[start].second << space << v[end].second;
                        return 0;
                    }else if(sum < x)
                        start++;
                    else
                        end--;
            }
        }
    }
    cout << -1;



    return 0;
}

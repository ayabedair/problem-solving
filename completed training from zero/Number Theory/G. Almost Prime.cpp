#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

bool almost_prime(int n){
    set<int>st;
    for(int i = 2; i * i <= n ; ++i){
        while(n % i == 0){
            st.insert(i);
            n /= i;
        }
    }
    if(n != 1) st.insert(n);
    return st.size() == 2;
}

int main() {
    int n; cin >> n;

    int cnt = 0;
    for(int i = 2 ; i <= n ; ++i)
        if(almost_prime(i))
            cnt++;

    cout << cnt;

    return 0;
}

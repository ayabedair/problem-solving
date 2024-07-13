#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> q(4);
    char s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        int t; cin >> t;

        if(s == 'C') q[0].push_back(t);
        else if(s == 'F') q[1].push_back(t);
        else if(s == 'P') q[2].push_back(t);
        else q[3].push_back(t);
    }

    int cnt = 0;
    for(int i = 0 ; i < 4 ; ++i){
        sort(q[i].begin(), q[i].end());
        int p = m;
        for(int j = 0 ; j < q[i].size() ; ++j){
            if(q[i][j] > p) break;
            p -= q[i][j];
            cnt++;
        }
    }

    cout << cnt << ln;

    return 0;
}



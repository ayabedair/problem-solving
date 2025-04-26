#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define mod 1000000007
#define int long long

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int sub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m;
}

int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
// int n, k, mx = LONG_MAX;
// vector<int> levels, vis;
vector<vector<int>> adj;
vector<char> v, s;
int n, m, d, sz;

int dp[351][3][301];

int rec(int i, bool greater, int sum) {
    if (i >= sz) {
        if (sum == d) return 1;
        return 0;
    }
    if (sum > d) return 0;

    int &ret = dp[i][greater][sum];
    if (~dp[i][greater][sum]) return ret;

    int ans = 0;
    int start = greater? 0 : s[i] - '0';
    for (int j = start; j <= 9; j++) {
        ans |= rec(i + 1, greater || j != s[i] - '0', sum + j);
    }

    return ret = ans;
}

void build(int i, bool greater, int sum) {
    // base case
    if (i >= sz) {
        return;
    }
    if (sum > d) return;

    int ans = 0;
    int start = greater? 0 : s[i] - '0';
    for (int j = start; j <= 9; j++) {
        ans |= rec(i + 1, greater || j != s[i] - '0', sum + j);
        if (ans == 1) {
            v.push_back(j + '0');
            build(i + 1, greater || j != s[i] - '0', sum + j);
            break;
        }
    }
}


void solve() {
    int n; cin >> n;
    s.assign(350, '0');
    sz = 350;
    memset(dp, -1, sizeof(dp));
    while (n--) {
        cin >> d;
        rec(0, false, 0);
        build(0, false, 0);
        int i = 0;
        while (v[i] == '0') {
            i++;
        }
        for (int j = i; j < v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
        for (int i = 0; i <= 9; ++i) {
            if ((v[v.size() - 1] - '0') == i) {
                v[v.size() - 1] = i + 1 + '0';
                break;
            }
        }
        s = v;
        sz = s.size();
        v.clear();
        memset(dp, -1, sizeof(dp));
    }
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}

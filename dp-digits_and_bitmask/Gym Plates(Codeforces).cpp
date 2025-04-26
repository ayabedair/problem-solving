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
vector<int> levels, vis;
vector<vector<int>> grid;
vector<int> v;
int n;
const int N = 59060;
int dp[101][N];

int getcount(int x, int i) {
    for (int j = 0; j < i; ++j) {
        x /= 3;
    }

    return x % 3;
}

void setcount(int& x, int i) {
    int power = 1;
    for (int j = 0; j < i; ++j) {
        power *= 3;
    }
    x += power;
}

int rec(int i, int mask) {
    if (i == n) return 0;

    if (~dp[i][mask]) return dp[i][mask];

    int ch1 = 0, ch2 = 0;
    ch2 = rec(i + 1, mask);
    int nn = v[i], f = 1, cp = mask;
    while (nn) {
        if (getcount(cp, nn % 10) > 1) {f = 0; break;}
        else setcount(cp, nn % 10);
        nn /= 10;
    }
    if (f) ch1 = rec(i + 1, cp) + v[i];

    return dp[i][mask] = max(ch1, ch2);
}

void solve() {
    cin >> n;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << "\n";
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}

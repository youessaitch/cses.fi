#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

ll solve(ll n, ll x, vector<ll> &v, vector<ll> &dp)
{
    if (x < 0)
        return 1e18;
    if (x == 0)
    {
        return 0;
    }

    if (dp[x] != -1)
        return dp[x];

    ll ans = 1e18;

    for (ll i = 0; i < n; i++)
    {
        ans = min(ans, 1 + solve(n, x - v[i], v, dp));
    }

    return dp[x] = ans;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    vector<ll> dp(x + 5, -1);
    ll ans = solve(n, x, v, dp);
    if (ans == 1e18)
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;

    return 0;
}
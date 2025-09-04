#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;
// bottom up approach (iterative) as top bottom giving tle bcuz of the deep recursion tree

// TOP BOTTOM:
ll solve(ll x, vector<ll> &dp)
{
    if (x < 0)
        return 1e18;
    if (x == 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    vector<int> v;
    int t = x;
    while (t > 0)
    {
        if (t % 10 != 0)
            v.push_back(t % 10);
        t /= 10;
    }

    ll ans = 1e18;
    for (int i = 0; i < v.size(); i++)
    {
        ans = min(ans, 1 + solve(x - v[i], dp));
    }

    return dp[x] = ans;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> dp(n + 5, -1);

    ll ans = solve(n, dp);
    cout << ans << endl;

    return 0;
}

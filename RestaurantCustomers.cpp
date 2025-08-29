#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    multimap<ll, ll> mpp;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        mpp.insert({a, 1});  // arrival
        mpp.insert({b, -1}); // departure
    }
    ll maxi = 0;
    ll cnt = 0;
    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        cnt += it->second;
        maxi = max(maxi, cnt);
    }
    cout << maxi << endl;
    return 0;
}
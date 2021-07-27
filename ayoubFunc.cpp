#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll numOfSubs(ll i, ll n){
    return n + (i - 1) * (n - i);
}

ll eq(ll n, ll m, ll part){
    ll a = m * (part + 1);
    ll b = (m + 1) * (part + 1);
    ll ans = a * ((2 * (n + 1)) - b);
    ans /= 2;
    return ans;
}

ll getFx(ll n, ll m){
    if(m == 0) return 0;
    double part = 1.0 * (n - m) / (m + 1);
    if(ceil(part) != floor(part)){
        ll k = m * (ceil(part) + 1) - n + ceil(part);
        ll a = eq(n, k, floor(part));
        ll b = eq(n - k * ceil(part), m - k, ceil(part));
        return a + b;
    } else {
        return eq(n, m, part);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll diff = m - ((n - 1) / 2), mxFx = 0;
        if(diff > 0){
            if(n % 2 == 0) diff++;
            mxFx += diff + getFx(n, (n - 1) / 2);
        }
        else mxFx = getFx(n, m);
        cout << mxFx << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
const ll INF = 1e18;
const int MOD = 1e9 + 7;
ll memo[105][105][105];
bool vis[105][105][105];
ll initx, inity, initz;

ll add(ll a, ll b, ll m = MOD) { 
    return ((a % m) + (b % m) + m) % m; 
}

ll sub(ll a, ll b, ll m = MOD) { 
    return ((a % m) - (b % m) + m) % m; 
}

ll mul(ll a, ll b, ll m = MOD) { 
    return ((a % m) * (b % m)) % m; 
}

ll modeexp(ll a, ll e, ll m = MOD) {    
    a %= m;
    ll r = 1;
    while(e) {
        if((e & 1)) r = mul(r, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return r;
}

ll inv(ll a, ll m = MOD) { 
    return modeexp(a, m - 2, m); 
}

struct Query {
    ll l, r, x, y;
};

long long solve(int i, int cnt2, int cnt3, ll n, vector<ll> &a, vector<ll> &b) {
    if(i == n) return 0;
    if(vis[i][cnt2][cnt3] != -1) return memo[i][cnt2][cnt3];
    
    ll x = initx - cnt2;
    ll y = inity - cnt2 - cnt3;
    ll z = initz - cnt3;

    ll maxsum = -INF;
    
    // Option 1: Type 1 - Subtract B[i]
    ll op1 = solve(i + 1, cnt2, cnt3, n, a, b) - b[i];
    maxsum = max(maxsum, op1);
    
    // Option 2: Type 2 - Decrease X and Y, add A[i] * new_X * new_Y * Z
    if(x > 0 && y > 0) {
        ll nx = x - 1;
        ll ny = y - 1;
        ll nz = z;
        ll gain = a[i] * nx * ny * nz;
        ll op2 = solve(i + 1, cnt2 + 1, cnt3, n, a, b) + gain;
        maxsum = max(maxsum, op2);
    }
    
    // Option 3: Type 3 - Decrease Y and Z, add A[i] * X * new_Y * new_Z
    if(z > 0 && y > 0) {
        ll nx = x;
        ll ny = y - 1;
        ll nz = z - 1;
        ll gain = a[i] * nx * ny * nz;
        ll op3 = solve(i + 1, cnt2, cnt3 + 1, n, a, b) + gain;
        maxsum = max(maxsum, op3);
    }
    vis[i][cnt2][cnt3]=true;
    return memo[i][cnt2][cnt3] = maxsum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
   ll n ;
 cin >> n;
cin >> initx >> inity >> initz;
vector<ll> a(n), b(n);
for(int i = 0; i < n; i++) cin >> a[i];
for(int i = 0; i < n; i++) cin >> b[i];

// ADD THIS TEMPORARILY:
cout << "DEBUG: N=" << n << " X=" << initx << " Y=" << inity << " Z=" << initz 
     << " A[0]=" << a[0] << " B[0]=" << b[0] << endl;
     
    memset(vis,false,sizeof(vis));
    ll maxsum = solve(0,0,0,n , a,b);
    ll ans = ((maxsum%MOD)+MOD)%MOD;
    cout<<ans<<nl;
    
    return 0;
}

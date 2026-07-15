#include <bits/stdc++.h>
using namespace std;
#define ll long long
int calculateMEX(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int mex = 0;
    for (int x : arr) {
        if (x == mex) {
            mex++;
        }
    }
    return mex;
}
int gapp(vector<int> & arr){
    sort(arr.begin(),arr.end());
    int cnt=0;
    int n = arr.size();
    for( int i=0;i<n;i++){
        if(arr[i] != i) cnt++;

    }
    return cnt;
}
int func(vector<int> & arr, int l){
    int sum =0;
    for( int i=0;i<l;i++){
        if(arr[l] > arr[i]) sum++;
    }
    return sum;
}
int func1(vector<int>&arr, int l ){
    int sum =0;
    for( int i=l+1;i<arr.size();i++){
        if(arr[l] < arr[i]) sum++;
    }
    return sum;
}
bool ispanlidrome( ll num){
    if(num<0) return false;
    string res = to_string(num);
    int l =0 , r = res.size()-1;
    while(l<=r){
        if(res[l] !=  res[r]) return false;
        l++;    
        r--;
    }
    return true;
}
void solve(){
        vector<vector<int>> edges = {{0,1},{1,2}};
        vector<int> basetime = {9,5,3};
        int n = basetime.size();
        auto ans = make_tuple(n,edges,basetime);
        vector<vector<int>> children(n);
        for(auto &e: edges){
            children[e[0]].push_back(e[1]);
        }
        auto dfs = [&] (auto&& self, int node) -> ll {
            if(children[node].empty()) return basetime[node];
            ll earliest = LLONG_MAX;
            ll latest = LLONG_MIN;
            for(int child : children[node]){
                ll x = self(self,child);
                earliest=min(earliest,x);
                latest=max(latest,x);
            }
            ll ownduration = (latest-earliest)+basetime[node];
            return latest+ownduration;
        };
        cout<<dfs(dfs,0)<<endl;
        
        
}
int main() {    
    ios_base::sync_with_stdio(false);       
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}

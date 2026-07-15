#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

 long long res =0,MOD =1000000007;
        for(int i=0;i<nums.size();i++){
            long long totalsum =0, mini=INT_MAX;
            for(int j=i;j<nums.size();j++){

                mini=min(mini,(long long)nums[j]);
                cout<<mini<<" : minimum" <<endl;
                totalsum+=nums[j];
                cout<<totalsum<<" : totalsum"<<endl;
                long long cur = (mini*totalsum)%MOD;
                cout<<cur<<" : current"<<endl;
                res=max(res,cur);
                cout<<res<<" : result"<<endl;
                cout<<" -------"<<endl;
            }
        }
        return res%MOD;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p;
    cin>>n>>p;
    vector<vector<int>> data(p);
    for(int i=0;i<p;i++){
        
    }
    // for(auto &d: data) {
    //     cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
    // }
    vector<int> count(n+1);
    for(auto &d : data ){
        count[d[0]]++;
        count[d[1]]++;
    }
    vector<int> vec;
    for(int i=0;i<count.size();i++){
        if(count[i] == 1) vec.push_back(i);
    }
    // for(int x: vec) cout<<x<<" ";
    //     cout<<endl;
    int nz = vec.size();
    for(int i=0;i<nz-1;i+=2){
        int a = vec[i], b = vec[i+1];
        int ans =-1;
        for(auto &d:data){
            if(d[0] == a || d[1] == a || d[0] == b || d[1] == b) {
                if(ans == -1) ans=d[2];
                ans= min(ans,d[2]);
            }

        }
        cout<<a<<" "<<b<<" "<<ans<<endl;
    }
    return 0;
}

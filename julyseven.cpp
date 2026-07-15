#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct catering{
	int d;
	int t;
	int s;

};
int x, n;
vector<vector<ll>> dp;
int powerSum(int remainig, int current) {
	int power= pow(current,n);
	if(remainig == 0) return 1;
	if(power>remainig) return 0;
	return powerSum(remainig-power,current+1)+powerSum(remainig,current+1);
}
ll dfs(vector<int> &coins, int target, int index){
	if(target == 0) return 1;
	if(target<0 || index == coins.size()) return 0;
	if(dp[index][target] != -1) return dp[index][target];
	return dp[index][target]=dfs(coins,target-coins[index], index)+dfs(coins,target,index+1);
}
int main() {
   int n , m;
   cin>>n>>m;
   vector<int> coins(m);
   for(int i=0;i<m;i++) cin>>coins[i];
   	dp.assign(m+1,vector<ll>(n+1,-1));
   cout<<dfs(coins,n,0);
}
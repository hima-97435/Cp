#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<pair<int,int>> vec;
vector<vector<int>> dp;
int dfs(int i , int j){
	if( i == vec.size()) return 0;
	if(dp[i][j+1] != -1) return dp[i][j+1];
	int mscore = j>=0?vec[j].first:0;
	int mage = j>=0 ?vec[j].second:0;
	int score = vec[i].first;
	int age = vec[i].second;
	int res =0;
	if(!(score>mscore && age<mage)) res=dfs(i+1,i)+score;
	dp[i][j+1]=max(res,dfs(i+1,j));
	return dp[i][j+1];
}

class SegmentTree{
private:
	int n ;
	vector<int> tree;
public:
	SegmentTree(int N ){
		n=N;
		while((n&(n-1))!= 0 ) n++;
		build();
	}
	void build() {
		tree.resize(2*n,0);
	}
	void update(int i , int val){
		int pos=n+i;
		tree[pos]=max(tree[pos],val);
		pos>>=1;
		while(pos>=1) {
			tree[pos]=max(tree[pos<<1], tree[pos<<1|1]);
			pos>>=1;
		}
	}
	int query(int l , int r){
		int res =0;
		l+=n;
		r+=n+1;
		while(l<r){
			if(l&1) {res=max(res,tree[l]); l++;}
			if(r&1) {r--;res=max(res,tree[r]);}
			l>>=1;
			r>>=1;
		}
		return res;
	}
};
int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> pairs(n);
        for(int i=0;i<n;i++) {
        	pairs[i]={scores[i],ages[i]};
        }
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n);
        for(int i=0;i<n;i++) dp[i]=pairs[i].first;
        set<int> uniqueageset;
	    for(auto&p: pairs){
	    	uniqueageset.insert(p.second);
	    }
	    vector<int> unquieage(uniqueageset.begin(), uniqueageset.end());
	    map<int, int> ageid;
	    for(int i=0;i<unquieage.size();i++){
	    	ageid[unquieage[i]]=i;
	    }
	    SegmentTree segtree(unquieage.size());
	    int res =0;
	    for(int i=0;i<n;i++){
	    	int mscore=pairs[i].first;
	    	int mage = pairs[i].second;
	    	int idx = ageid[mage];
	    	int j = segtree.query(0,idx);
	    	dp[i]=j+mscore;
	    	segtree.update(idx,dp[i]);
	    	res=max(res,dp[i]);
	    }
	    return res;
    }
ll sumofdigit(ll n){
	ll sum =0;
	while(n!=0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(){
	int n ;
	cin>>n;
	vector<vector<int>> ans(n+1, vector<int>(n+1,-1));
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			set<pair<int, int>> st ={
			{i,j},{i,-j},{-i,j},{-i,-j},
			{j,i},{j,-i},{-j,i},{-j,-i}
		};
			vector<pair<int, int>> dir(st.begin(),st.end());
			vector<vector<bool>> vis(n,vector<bool>(n,false));
			queue<tuple<int, int, int>> q;
			q.push({0,0,0});
			vis[0][0]=true;
			while(!q.empty()){
					auto[s1 ,s2,dis]=q.front();
					q.pop();
					if(s1 == n-1 && s2 == n-1) {ans[i][j]= dis; ans[j][i]=dis; break;}
					for(auto&d: dir){
						int nr = s1+d.first;
						int nc = s2+d.second;
						
						if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]) {vis[nr][nc]=true; q.push({nr,nc, dis+1});}
					}
					
					// if(s1+i<n  && s2+j<n && s1+i>=0 && s2+j>=0 && !vis[s1+i][s2+j] ) {vis[s1+i][s2+j]= true; q.push({s1+i,s2+j,dis+1});}
					// if(s1+i<n  && s2-j<n && s1+i>=0 && s2-j>=0 && !vis[s1+i][s2-j] ) {vis[s1+i][s2-j]= true; q.push({s1+i,s2-j,dis+1});}
					// if(s1-i<n  && s2+j<n && s1-i>=0 && s2+j>=0 && !vis[s1-i][s2+j] ) {vis[s1-i][s2+j]= true; q.push({s1-i,s2+j,dis+1});}
					// if(s1-i<n  && s2-j<n && s1-i>=0 && s2-j>=0 && !vis[s1-i][s2-j] ) {vis[s1-i][s2-j]= true; q.push({s1-i,s2-j,dis+1});}
					
					// if(s1+j<n  && s2+i<n && s1+j>=0 && s2+i>=0 && !vis[s1+j][s2+i] ) {vis[s1+j][s2+i]= true; q.push({s1+j,s2+i,dis+1});}
					// if(s1+j<n  && s2-i<n && s1+j>=0 && s2-i>=0 && !vis[s1+j][s2-i] ) {vis[s1+j][s2-i]= true; q.push({s1+j,s2-i,dis+1});}
					// if(s1-j<n  && s2+i<n && s1-j>=0 && s2+i>=0 && !vis[s1-j][s2+i] ) {vis[s1-j][s2+i]= true; q.push({s1-j,s2+i,dis+1});}
					// if(s1-j<n  && s2-i<n && s1-j>=0 && s2-i>=0 && !vis[s1-j][s2-i] ) {vis[s1-j][s2-i]= true; q.push({s1-j,s2-i,dis+1});}
				
				
			} 
			
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
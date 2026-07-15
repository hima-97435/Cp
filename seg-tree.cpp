#include<bits/stdc++.h>
using namespace std;
#define ll long long
class SegmentTree{
	int n;
	vector<pair<int,ll>> tree;
public:
	SegmentTree(int n , vector<int>&nums) : n(n){
		while((this->n & (this->n -1)) != 0 ) this->n++;
		build(n, nums);
	}
	void build(int n , vector<int>& nums){
		tree.resize(2*this->n , {-1, LLONG_MAX});
		for(int i=0;i<n;i++){
			tree[this->n+i] = {i, nums[i]};
		}
		for(int i=this->n-1;i>0;i--){
			tree[i]=min(tree[i<<1], tree[i<<1|1],[](auto &a, auto &b){
				return a.second<b.second;
			});
		}

	}
	int query( int l , int r){
		pair<int , ll> res = {-1,LLONG_MAX};
		l+=this->n;
		r+=this->n+1;
		while(l<r) {
			if(l&1 ) res= min(res, tree[l++], [](auto &a, auto&b){
				return a.second<b.second;
			});
			if(r&1) res= min(res, tree[--r],[](auto&a, auto&b){
				return a.second<b.second;
			});
				l>>=1;
				r>>=1;
		}
		return res.first;
	}
};
class Solution{
public: 
	int maxSumMinProduct(vector<int>& nums){
		const int MOD = 1e9+7;
		SegmentTree segtree(nums.size(), nums);
		vector<ll> prefixsum(nums.size()+1,0);
		for(int i=0;i<nums.size();i++){
			prefixsum[i+1]= prefixsum[i]+nums[i];
		}
		return rec(0, nums.size()-1, nums, prefixsum,segtree)%MOD;
	}
private:
	ll rec( int l , int r, vector<int>&nums, vector<ll>& prefixsum, SegmentTree& segtree){
		if(l>r ) return 0;
		int mindex=segtree.query(l,r);
		ll totalsum = prefixsum[r+1]-prefixsum[l];
		ll cur = totalsum*nums[mindex];
		ll left = rec(l , mindex-1,nums, prefixsum,segtree);
		ll right = rec(mindex+1,r,nums, prefixsum, segtree);
		return max(cur,max(left,right));
	} 
};
int main(){
	Solution s = Solution();
	// vector<int> nums= {4,5,1,6,7};
	// cout<<s.maxSumMinProduct(nums)<<endl;
	cout<<(5>>1)<<(6>>1)<<endl;
}
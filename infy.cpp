#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// vector<vector<int>>  waterconnection(int n , vector<int>&a, vector<int> &b , vector<int>&d){
// 	int p = a.size();
// 	vector<int> outnode(n+1,0);
// 	vector<int> weights(n+1,0);
// 	vector<int> indegree(n+1,0);
// 	vector<int> outdegree(n+1,0);
// 	for(int i=0;i<p;i++){
// 		outnode[a[i]]=b[i];
// 		weights[a[i]]=d[i];
// 		indegree[b[i]]=1;
// 		outdegree[a[i]]=1;
// 	}
// 	vector<vector<int>> ans;
// 	for(int i=1;i<=n;i++){
// 		if(indegree[i] == 0 &&outdegree[i] == 1) {
// 			int current =i;
// 			int min_diameter = 1e9;
// 			while(outdegree[current] == 1) {
// 				min_diameter=min(min_diameter,weights[current]);
// 				current=outnode[current];
// 			}
// 			ans.push_back({i,current,min_diameter});
// 		}
// 	}
// 	sort(ans.begin(),ans.end());
// 	return ans;
// }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p;
    cin>>n>>p;
    vector<int> a(n),b(n),d(n);
    for(int i=0;i<p;i++) cin>>a[i]>>b[i]>>d[i];
    auto waterconnection = [&] ( int n , vector<int>&a, vector<int>&b, vector<int>&d) -> auto {
    	int p = a.size();
	vector<int> outnode(n+1,0);
	vector<int> weights(n+1,0);
	vector<int> indegree(n+1,0);
	vector<int> outdegree(n+1,0);
	for(int i=0;i<p;i++){
		outnode[a[i]]=b[i];
		weights[a[i]]=d[i];
		indegree[b[i]]=1;
		outdegree[a[i]]=1;
	}
	vector<vector<int>> ans;
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0 &&outdegree[i] == 1) {
			int current =i;
			int min_diameter = 1e9;
			while(outdegree[current] == 1) {
				min_diameter=min(min_diameter,weights[current]);
				current=outnode[current];
			}
			ans.push_back({i,current,min_diameter});
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
    };
    vector<vector<int>> res = waterconnection(n,a,b,d);
	for(auto &d : res){
		cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
	}
    return 0;
}

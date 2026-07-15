#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
string s;
vector<vector<int>> pref;
vector<ll> fact,inversefact;
ll power( ll  base, ll exp){
	ll res =1;
	base%=MOD;
	while(exp>0){
		if(exp%2  == 1 ) res=(res*base)%MOD;
		base=(base*base)%MOD;
		exp/=2;
	}
	return res;
}
ll modinverse(ll n){
	return power(n,MOD-2);
}
void intialise(const string &s){
	int n = s.size();
	fact.resize(n+1,1);
	inversefact.resize(n+1,1);
	for(int i=1;i<=n;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	inversefact[n]=modinverse(fact[n]);
	for(int i=n-1;i>=1;i--){
		inversefact[i]=(inversefact[i+1]*(i+1))%MOD;
	}
	pref.resize(n+1,vector<int>(26,0));
	for(int i=0;i<n;i++){
		for(int c=0;c<26;c++) {
			pref[i+1][c]=pref[i][c];
		}
		pref[i+1][s[i]-'a']++;
	}
}
void solve(){
	int l , r;
	cin>>l>>r;
	int totalpairs =0;
	int oddtypes =0;

	ll numerator =1;
	ll denomintor_inverse = 1;
	for(int c=0;c<26;c++){
		int count = pref[r][c]-pref[l-1][c];
		int pairscount = count/2;
		if(pairscount>0) {
			totalpairs+=pairscount;
			denomintor_inverse=(denomintor_inverse*inversefact[pairscount])%MOD;
		}
		if(count %2 != 0 ) oddtypes++;
	}

	
	ll uniquelefthaves= (fact[totalpairs]*denomintor_inverse)%MOD;

	ll totalpalindrome=uniquelefthaves;
	if(oddtypes>0) totalpalindrome=(totalpalindrome*oddtypes)%MOD;
	cout<<totalpalindrome<<"\n";
}
void solve1(){
	int n ;
	cin>>n;
	vector<string> db(n);
	for(int i=0;i<n;i++){
		cin>>db[i];
	}
	string actual;
	cin>>actual;
	vector<int> dp(actual.size(),-1);

	vector<string> answer;
	auto dfs= [&](auto&&self, int index) ->bool{
		if(index  == actual.size()) return true;
		if(dp[index] == 0) return false;
		for(const string s : db){
			if(actual.compare(index, s.size(),s) == 0 ) {
				answer.push_back(s);
				if(self(self,index+s.size()))  return true;;
				answer.pop_back();
			}

		}
		return dp[index]= 0;
	};
	if(dfs(dfs,0)) {
		for(int i = 0; i < answer.size(); i++) {
		    if(i) cout << " ";
		    cout << answer[i];
		}
		cout << "\n";
	}
	else cout<<"WRONG PASSWORD"<<"\n";
}
class Solution {
public:
    int minSetSize(vector<int>& rr) {
        unordered_map<int, int> mp;
        for(int x: rr) mp[x]++;
        vector<int> arr;
        for(auto &p : mp) {
        arr.push_back(p.second);
    	}
    	sort(arr.rbegin(),arr.rend());
    	int count =0;
    	int selected =0;
    	for(int i=0;i<arr.size();i++){
    		selected+=arr[i];
    		count++;
    		if(selected>=rr.size()/2) return count;
    		
    	}
    	return count;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
     sort(boxTypes.begin(), boxTypes.end(),
     	[](vector<int>&a, vector<int>&b){
     		return a[1]>b[1];
     	}); 
     int ans =0;
     for(auto &box : boxTypes){
     	int boxes = box[0];
     	int units = box[1];
     	int take = min(boxes, truckSize);
     	ans+=take*units;
     	truckSize-=take;
     	if(truckSize == 0) return ans;
     }
     return ans;
    }
     long long minimumReplacement(vector<int>& nums) {
     int limit = nums[nums.size()-1];
     ll cnt = 0;
     for(int i=nums.size()-2;i>=0;i--){
     	if(nums[i]>limit){
     		int spilt = (nums[i]+limit-1)/limit;
     		limit=nums[i]/spilt;
     		cnt+=spilt-1;
     	}
     	else {
     		limit=nums[i];
     	}
     }   
     return cnt;
    }
    bool lemonadeChange(vector<int>& bills) {
        int five =0;
        int ten =0;
        for(int x: bills){
            if(x == 5) {
                five++;
            }
            else if(x == 10 ){
                if(five>= 1){five--;ten++;}
                else return false;
            }
            else {
                if(five>=3) {five-=3;}
                else if(five>=1 && ten>=1) {five-=2; ten-=1;}
                else return false;
            }
            cout<<"Five: "<<five<<" Ten: "<< ten<<endl;
        }
        return true;

    }
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(), m = abbr.size();
        cout<<n<<" "<<m<<endl;
        int i=0, j=0;
        while(i<n && j<m){
        	
        	if(isalpha(abbr[j]) ) {
        		if(word[i] == abbr[j]) {i++;j++;}
        		else return false;
        	}
        	else {
        		if(abbr[j] == '0') return false;
        		int z =j;
        		while(j<m && isdigit(abbr[j])) j++;
        		// cout<<abbr.substr(z,j-z)<<endl;
        		i+=stoi(abbr.substr(z,j-z));
        	}
        	cout<<"i : "<<i<<" j: "<<j<<"\n";
        }

        return i == n && j == m;
    }
};
void solve2(){

}
int main(){
	/* 
	Arrival and Departure Time in DFS
	Input: 
	6 7
	0 1
	0 2
	1 3
	1 4
	2 5
	3 5
	4 5
	Output:
	0 1 9 2 6 3 
	11 8 10 5 7 4 

	int v, e;
	cin>>v>>e;
	vector<vector<int>> adj(v);
	for(int i=0;i<e;i++) {
		int nx, ny;
		cin>>nx>>ny;
		adj[nx].push_back(ny);

	}
	vector<int> arrival(v,0);
	vector<int> deprature(v,0);
	vector<bool> visited(v,false);
	int time =0;
	auto dfs = [&] (auto &&self, int vertex)->void{
		if(visited[vertex]) return;
		arrival[vertex]=time;
		time++;
		visited[vertex]=true;
		for(int x : adj[vertex]){
			self(self,x);
		}
		deprature[vertex]=time;
		time++;
	};
	for(int i=0;i<v;i++) if(!visited[i]) dfs(dfs,i);
	for(int x: arrival) cout<<x<<" ";
		cout<<endl;
	for(int x: deprature) cout<<x<<" ";
		cout<<endl;
	*/
	/*
	Construct the Longest Palindrome by Reordering or Deleting Characters
	Input: 
	ABBDAB
	Output:
	BABAB
	string x ;
	cin>>x;
	unordered_map<char, int> mp; //  can you vector<int>(26,0);
	for(char c: x) mp[c]++;
	string left="";
	string middle="";
	for(auto&p: mp){
		int cnt = p.second;
		int pairs = cnt/2;
		left.append(pairs,p.first);
		if(cnt%2 != 0) middle=p.first;
	}
	string r= left;
	reverse(r.begin(), r.end());
	left+=middle;
	left+=r;
	cout<<left<<endl;
	*/
	/*
	Card Game (Suneet and Slavic)
	int q;
	cin>>q;
	while(q--){
		int a1,a2,b1,b2;
		cin>>a1>>a2>>b1>>b2;
		int count =0;
		if(a1>b1 && a2>b2) count++;
		if(a1>b2 && a2>b1) count++;
		if(a2>b1 && a1>b2) count++;
		if(a2>b2 && a1>b1) count++;
		cout<<count<<endl;
	}
	*/
	/*
	Question 19: White and Black Cells (Sliding Window)	
	Input:
	4
	5 3
	BBWBW
	5 5
	BBWBW
	5 1
	BBWBW
	1 1
	W
	Output:
	1
	2
	0
	1	
	int q;
	cin>>q;
	while(q--){
		int n , k;
		cin>>n>>k;
		string s;
		cin>>s;
		int blackcount=0, whitecount=0;
		int minsteps = INT_MAX;
		for(int i=0;i<n;i++){
			if(s[i] == 'W') whitecount++;
			else blackcount++;
			if(blackcount+whitecount == k) // window is fixed
			{
				minsteps=min(minsteps,whitecount);
				
			}
			if(i-k>=0) {
				if(s[i-k] == 'W') whitecount--;
				else blackcount--;
			}
		}
		cout<<minsteps<<"\n";
		
	}
	*/
	/* 
	VwV Language (Underline Count)
	Input: 
	5
	vv
	v
	w
	vwv
	vwvvwv
	Output:
	1
	0
	1
	1
	3
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		int cnt =0;
		for(int i=0;i<s.size();i++){
			if(i>0) {if(s[i] == 'v' && s[i-1] == 'v') {cnt++;i++;}}
			if(s[i] == 'w') cnt++;
		}
		cout<<cnt<<"\n";
	}
	*/
/*
Question 21: Count Digit Changes
Input: 
4
1 9
9 10
10 20
1 1000000000
Ouptut:
8
2
11
1111111110

	int q;
	cin>>q;
	while(q--){
		int l , r;
		cin>>l>>r;
		
		// auto findnines = [&](int n )->int{
		// 	int cnt =0;
		// 	while(n%10 == 9) {cnt++; n/=10;}
		// 	return cnt;
		// };
// logic is to count numbers which are ending up with 9 , 99 , 999 and so on 
		ll ans =r-l;
		for(ll p  = 10;p<=r;p*=10){
			ans+=r/p-l/p;
		}

		cout<<ans<<"\n";
	}
*/
	/* 
	Question 22: Board with Chips (Grid Traversal)

	int n , m , k;
	cin>>n>>m>>k;
	vector<vector<int>> start, target;
	for(int i=0;i<k;i++) {
		int x,y;
		cin>>x>>y;
		start.push_back({x,y});
	}
	for(int i=0;i<k;i++){
		int x, y;
		cin>>x>>y;
		target.push_back({x,y});
	}
	int u = INT_MIN, l=INT_MIN;
	for(auto t: start){
		int ax = t[0], ay=t[1];
		int stepsup=ax-1;
		int stepsleft=ay-1;
		u=max(u,stepsup);
		l=max(l,stepsleft);
	}
	string ans="";
	ans.append(u,'U');
	ans.append(l,'L');
	// cout<<ans<<endl;
	int row=1,col=1;
	for(int i=row;i<=n;i++)
	{	
		if(i%2 != 0) {
			// odd 
			int temp = m-1;
			while(temp--) ans+='R';
		}
		else {
			//even  LLL
			int temp = m-1;
			while(temp--) ans+='L';

		}
		if(i!=n) ans+='D';
	}
	cout<<ans.size()<<endl<<ans;
	*/
		int t;
		cin>>t;
		while(t--){
			int n ;
			cin>>n;
			int one =0, zero =0;
			vector<int> arr;
			while(n--){
				string s;
				cin>>s;
				arr.push_back(s.size());
				for(char c: s){
					if(c == '1' ) one++;
					else zero++;	
				}
			}
			int pa=(one/2)+(zero/2);
			int leftover=0;
			if(one%2!= 0) leftover++;
			if(zero%2!= 0) leftover++;
			int cnt =0;
			sort(arr.begin(),arr.end(),[](int a, int b){
				return (a/2)<(b/2);
			});
			cout<<pa<<" "<<leftover<<endl;
			for(int x: arr){
				int need = x/2;
				int need2=0;
				if(x%2 != 0) need2=1; 
				if(pa>=need) pa-=need;
				else break;
				if(leftover>=need2) leftover-=need2;
				else {
					if(pa>0) // ek pair hai
					{
						pa--;
						leftover+=2;
					}
					if(leftover>=need2) leftover-=need2;
					else break;
				}
				cout<<"X : "<<x<<" "<<pa<<" "<<leftover<<endl;
				cnt++;
			}
			cout<<cnt<<endl;
	}
}
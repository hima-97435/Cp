#include<bits/stdc++.h>
using namespace std;
void solve(){
		int n ;
		cin>>n;
		string s;
		cin>>s;
		// for(int i=0;i<n-1;){
		// 	cout<<i<<" ";
		// 	cout<<s[i]<<" "<<s[i+1]<<"\n";
		// 	if(s[i] == s[i+1]) i+=2;
		// 	else {
		// 		if(s[i+1] == '_') // if there is a charcter in future as same as s[i] we could transport it .
		// 		{
		// 			bool flg=  false;
		// 			for(int j=i+1;i<n;j++){
		// 				// cout<<"Forward pass: ";
		// 				// cout<<s[i]<<" "<<s[j]<<endl;
		// 				if(s[j] == s[i]) {flg=true; break;} 
		// 			}
		// 			if(flg) i+=2;
		// 			else {cout<<"NO"<<"\n"; return;}
		// 		}
		// 		else {cout<<"NO"<<"\n"; return;}
		// 	}
		// }
		// cout<<"YES"<<"\n";
		bool helper = false;
		for(char c: s) if(c =='_') helper=true;
		if(helper){
			unordered_map<char, int> mp;
			for(char c: s) if(c != '_') mp[c]++;
			for(auto &p: mp) {
				if(p.second == 1 ) {cout<<"NO"<<"\n";return;} 
			}
			cout<<"YES"<<"\n";
		}
		else {
			for(int i=0;i<n;i++){
				bool l = (i>0 && s[i] == s[i-1]);
				bool r = (i<n-1 && s[i] == s[i+1]);
				if(!(l || r)) {
					// unhappy
					cout<<"NO"<<"\n"; 
					return;
				}
				// cout<<i<<" "<<s[i-1]<<" "<<s[i]<<" "<<s[i+1]<<endl;
				// if( (i>0 && s[i] != s[i+1] || s[i] != s[i-1]) || ( i == 0 && s[i] != s[i+1]) ) {cout<<"NO"<<"\n";return;} 
			}
			cout<<"YES"<<"\n";
		}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
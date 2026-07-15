#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Event{
		ll coord;
		int type;
		int id;

		bool operator<(const Event& other ) const{
			if(coord!=other.coord) {
				return coord<other.coord;
			}
			return type<other.type;
		};
	};
long maximumPeople(vector<long> p={10,100}, vector<long> x={5,100}, vector<long> y={4} , vector<long> r={1}) {
	
	int n = p.size();
	int m = y.size();
	vector<Event> events;
	for(int i=0;i<n;i++) events.push_back({x[i],1,i});
	for(int i=0;i<m;i++){
		ll start = (ll)y[i]-r[i];
		ll end = (ll)y[i]+r[i];
		events.push_back({start,0,i});
		events.push_back({end,2,i});
	}
	sort(events.begin(), events.end());
	unordered_set<int> st;
	ll awlys_sunny=0;
	vector<ll> cloudbenefits(m,0);
	for(auto&e: events){
		if(e.type == 0) st.insert(e.id);
		else if(e.type == 2) st.erase(e.id);
		else {
			if(st.empty()) awlys_sunny+=p[e.id];
			else if(st.size() == 1) {
				ll cloud_id = *st.begin();
				cloudbenefits[cloud_id]+=p[e.id];
			}
		}
	}
	long long maxbenefits=0;
	for(int i=0;i<m;i++) {
		if(cloudbenefits[i]>maxbenefits) maxbenefits=cloudbenefits[i];
	}
	return awlys_sunny+maxbenefits;
}
void getcomponent(ll node, vector<vector<ll>>&adj, vector<bool>&vis, ll& count){
	vis[node]=true;
	count++;
	for(int n : adj[node]){
		if(!vis[n]) getcomponent(n,adj,vis,count);
	}
}
ll journeyToMoon(ll n, vector<vector<ll>> astronaut) {
	vector<vector<ll>> adj(n);
	for(const auto&p: astronaut){
		adj[p[0]].push_back(p[1]);
		adj[p[1]].push_back(p[0]);
	}
	vector<bool> vis(n , false);
	vector<ll> countrysize;
	for(ll i=0;i<n;i++){
		if(!vis[i]){
			ll current_country_size=0;
			getcomponent(i,adj,vis,current_country_size);
			countrysize.push_back(current_country_size);
		}
	}
	ll validpairs=0;
	ll processed_astronauts=0;
	for( ll size : countrysize) {
		validpairs+=size*processed_astronauts;
		processed_astronauts+=size;
	}
	return validpairs;
}
int main(){
	ll n , p;
	cin>>n>>p;
	vector<vector<ll>> astronaut(p);
	for(ll i=0;i<p;i++){
		ll x, y;
		cin>>x>>y;
		astronaut[i]={x,y};

	}
	cout<<journeyToMoon(n,astronaut);
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e18
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
#define vi vector< int >
#define vii vector< pii >

#define maxn 

int32_t main(){
	DESYNC;
	int n,b;
	cin>>n>>b;
	int vet[n];
	vi v;
	int a = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>vet[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if(vet[i]%2){
			a++;
		}else a--;
		
		if(!a && i!=n-1){
			int b = 0;
			for (int j = i+1; j < n; ++j)
			{
				if(vet[j]%2){
					b++;
				}else b--;
				//cout<<vet[j]<<endl;
			}
			//cout<<b<<endl;

			if(!b){
				v.pb(abs(vet[i]-vet[i+1]));
			}
		}
	}
	sort(v.begin(), v.end());
	int tot = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		//cout<<v[i]<<endl;
		if(v[i]<=b){
			tot++;
			b-=v[i];
		}else break;
	}
	cout<<tot<<endl;


}
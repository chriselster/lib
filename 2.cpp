#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e18
#define endl '\n'
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
	int n;
	cin>>n;
	if(!(n%2)){
		cout<<"NO"<<endl;
		return 0;
	}
	int i=1,k=1;
	vii ans;
	int maior = 0;
	for (i = 1; i <= n; ++i)
	{
		//primeiros n
		ans.pb(mp(1,(i+1)));
		if(i+1>maior)maior = i+1;
		//2 até 1+n
		for (int j = 1; j <= n-1; ++j)
		{
			//n-1
			int buceta = j+(i-1)*(n-1)+n+1;
			ans.pb(mp((i+1),buceta));
			if(buceta>maior)maior = buceta;
			for (k = 1; k <= n-1; ++k)
			{
				//n-1 dentro
				int cu = (i+n-1)*(n-1)+n+k+1;
				ans.pb(mp(buceta,cu));
				if(j==1&&k%2){
					ans.pb(mp(cu,cu+1));
				}
				if(cu>maior)maior = cu;
			}
		}
	}
	cout<<"YES"<<endl;
	cout<<maior<<" "<<ans.size()<<endl;
	for(auto a:ans){
		cout<<a.first<<" "<<a.second<<endl;
	}

	// cout<<endl;
	// cout<<1+n+2*(n-1)*n<<" ";
	// cout<<n+n*(n-1)+n*(n-1)*(n-1)+n*(n-1)/2<<endl;
}

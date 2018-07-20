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

#define maxn 100

struct caixa
{
	int p,r,res;
};

bool cmp(caixa a, caixa b){
	if(a.res == b.res)return a.p<b.p;
	else return a.res>b.res;
}

int n,dp[maxn][maxn];

int empilha(int a, int r,int tam){
	if(r<1 || tam  == n || a == n)return 0;

	if(dp[a][tam] != -1)return dp[a][tam];

	int x = empilha(a+1, r-v[a].p, tam +1);
	int y = empilha(a+1,r,tam);
	return dp[a][r] = max(x,y);
}

int32_t main(){
	DESYNC;
	cin>>n;
	vector<caixa> v;
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		caixa a;
		int p,r,res;
		cin>>p>>res;
		r = res - p;
		if(r>0){
			a.p = p;
			a.r = r;
			a.res = res;
			v.pb(a);
		}
	}
	sort(v.begin(), v.end(),cmp);

	empilha(0, INF, 0);
}
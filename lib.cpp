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
#define maxn 1000000

//MATEMATICA
bitset<maxn> primo;
void crivo(int n){
	primo.set();
	primo[1]=false;
	for (int p = 2; p*p <= n; ++p)
	{
		if(primo[p])
			for (int j = p*p; j <= n; j+=p)
			{
				primo[j]=false;
			}
	}
	return;
}
//CONJUNTOS 
set< vi > subsets( vi A, int N)
{
	set< vi > s;
    for(int i = 0;i < (1 << N); ++i)
    {
		vi v;
        for(int j = 0;j < N;++j)
            if(i & (1 << j))
                v.pb(A[j]);
        s.insert(v);
	}
	return s;
}

//GRAFOS
//dfs
//definir componente inicial e memset
int componente[maxn];
void dfs(int x){

	for (int i = 0; i < v[x].size(); ++i)
	{
		int next = v[x][i];
		if(componente[next] != -1)continue;
		componente[next] = componente[x];
		dfs(next);
	}
	return;
}

//FloodFill
int n,m,x,y;
int visto[maxn][maxn];
int d[5]={-1,0,1,0,-1};
char v[maxn][maxn];
int  floodFill(int a, int b){
	if(a==x&&b==y){
		if(v[x][y]=='X')return 1;
		for (int i = 0; i < 4; ++i)
		{
			int l,k;
			l = a+d[i];
			k = b+d[i+1];
			if(l>=0&&l<n&&k>=0&&k<m&&v[l][k]=='.')return 1;
		}
		return 0;
	}
	if(a<0||a>=n||b<0||b>=m||v[a][b]!='.')return 0;
	if(visto[a][b])return 0;
	v[a][b]='X';
	visto[a][b]=1;
	for (int i = 0; i < 4; ++i)
	{
		if(floodFill(a+d[i],b+d[i+1]))return 1;
	}
	v[a][b]='.';
	return 0;
}
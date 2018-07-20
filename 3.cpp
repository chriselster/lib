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
#define maxn 100001
int tot;

	int a,b,c;

int32_t main(){
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*m; ++j)
		{
			int aux;
			cin>>aux;
			if(aux == 11){
				a++;
			}else if(aux==0){
				b++;
			}
			else c++;
		}
	}
	string d[6] = {"11 ", "00 ", "10 ","00 ","11 ", "01 "};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*m; ++j)
		{
			if(i%2){
				if(v[j%3])cout<<"11 "
				else cout
			}
		}
	}
}
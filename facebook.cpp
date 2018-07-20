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

void teste(string a, string b){
	int j = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if(a[i] != b[j++])i=0;
		if(j == b.size()){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	return;
}

int32_t main(){
	DESYNC;
	int t;
	cin>>t;

	for (int u = 0; u < t; ++u)
	{
		cout<<"Case #"<<u+1<<": ";

		string s,aux ="";
		cin>>s;
		aux+=s[0];
		int i;
		for (i = 1; i < s.size(); ++i)
		{
			if(s[i]!= s[0])aux+=s[i];
			else break;
		}
		if(aux.size()==s.size()){
			cout<<"Impossible"<<endl;
			continue;
		}

		int pos = s.find(aux, i);
		if(pos != -1){
			cout<<"Impossible"<<endl;
			continue;
		}

		aux += s;
		cout<<aux<<"\n";
	}
}
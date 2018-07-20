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
#define maxn 1000001
int tot;

struct edg
{
	int first,second,third;
};
int processado[maxn];
edg distancia[maxn];  
vector<edg> vizinhos[maxn];
int sla[maxn];
set<int> ans;
int n,m;
void Dijkstra(int S){
	
	for(int i = 1;i <= n;i++) distancia[i].first = INF; 
	distancia[S].first = 0;
	
	priority_queue< pii, vector<pii>, greater<pii> > fila;
	fila.push( mp(distancia[S].first, S) );
	
	while(true){
		int davez = -1;
		int menor = INF;
		
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){
				davez = atual;
				break;
			}
			
		}
		
		if(davez == -1) break;
		processado[davez] = true; // marcamos para não voltar para este vértice
		
		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			int dist  = vizinhos[davez][i].second;
			int atual = vizinhos[davez][i].first;

			int u = vizinhos[davez][i].third;
			//cout<<distancia[atual].first<<" "<<distancia[davez].first + dist<<endl;
			if( distancia[atual].first >= distancia[davez].first + dist ){  // vemos que vale a pena usar o vértice davez
				distancia[atual].second = distancia[davez].second + 1;
				distancia[atual].first = distancia[davez].first + dist;    // atualizamos a distância
				ans.erase(distancia[atual].third);
				tot-=sla[distancia[atual].third];
				distancia[atual].third = u;
				tot+=sla[u];
				ans.insert(u);
				fila.push( pii(distancia[atual].first, atual) );     // inserimos na fila de prioridade
			}
		}
	}
	
}
int32_t main(){
    DESYNC;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c,d;
		cin>>a>>b>>c;
		d = i+1;
		sla[d]=c;
		vizinhos[a].pb({b,c,d});
		vizinhos[b].pb({a,c,d});
	}
	int x;
	cin>>x;
	Dijkstra(x);
	
	cout<<tot<<endl;
	for(auto a:ans){
		cout<<a<<" ";
	}
	cout<<endl;
}
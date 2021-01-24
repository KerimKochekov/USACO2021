#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int a[MAXN],b[MAXN],ans[MAXN],mark[MAXN],arr[MAXN],dar[MAXN];
vector<PII>vis[MAXN];
int pm[MAXN],uni;
stack<int>st;
void add(int x){
	uni+=(!pm[x]);pm[x]++;st.push(x);
}
void rem(int x){
	pm[x]--;uni-=(!pm[x]);
}
int main(){
    //freopen("file.in", "r", stdin);
    int n,k;ll m;
    scanf("%d%d%lld",&n,&k,&m);
    for(int i=1;i<=k;i++)scanf("%d%d",a+i,b+i);umin(m,n*1LL*k);
    for(int i=1;i<=n;i++)dar[i]=i,vis[i].pb(mp(0,i));
    for(int i=1;i<=k;i++){
    	int x=a[i],y=b[i];
		for(int j=0;j<2;j++)
			vis[dar[x]].pb(mp(i,y)),swap(x,y);
    	swap(dar[x],dar[y]);
    }ll bro=m/k,broski=m%k;
    vector<int>cycle;
    for(int i=1;i<=n;i++)arr[dar[i]]=i;
    for(int i=1;i<=n;i++)
    	if(!mark[i]){
    		cycle.clear();
    		int to=i;
			do{cycle.pb(to);mark[to]=1;to=arr[to];}while(to!=i);
			int sz=int(cycle.size());
			if(sz<=bro){	
				for(int j=0;j<sz;j++)
					tr(it,vis[cycle[j]])
						add(it->ss);
				for(int j=0;j<sz;j++)ans[cycle[j]]=uni;
			}
			else{
				for(int j=0;j<bro;j++)
					tr(it,vis[cycle[j]])
						add(it->ss);
				for(int j=0,h;j<sz;j++){
					int to=(j+bro)%sz;
					for(h=0;h<vis[cycle[to]].size() and vis[cycle[to]][h].ff<=broski;h++)
						add(vis[cycle[to]][h].ss);
					ans[cycle[j]]=uni;
					for(h=0;h<vis[cycle[to]].size() and vis[cycle[to]][h].ff<=broski;h++)
						rem(vis[cycle[to]][h].ss);
					tr(it,vis[cycle[j]])rem(it->ss);
					tr(it,vis[cycle[to]])add(it->ss);
				}
			}
			while(!st.empty())pm[st.top()]=0,st.pop();uni=0;
    	}
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}


#include "bits/stdc++.h"
#define MAXN 100009
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
const int K=52;
int last[K],l[MAXN][K],r[MAXN][K],arr[MAXN],dis[MAXN];
char s[K][K];
int main(){
    //freopen("file.in", "r", stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    	scanf("%d",arr+i);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=k;j++)
			l[i][j]=last[j];
		last[arr[i]]=i;	
    }for(int i=1;i<=k;i++)last[i]=0;
    for(int i=n;i>=1;i--){
    	for(int j=1;j<=k;j++)
			r[i][j]=last[j];
		last[arr[i]]=i;	
    }
    for(int i=1;i<=k;i++)
    	scanf("%s",s[i]+1);
    for(int i=1;i<=k;i++)s[i][i]='1';
    s[arr[1]][arr[1]]='0';
    for(int i=2;i<=n;i++)dis[i]=INF;
    queue<int>q;q.push(1);
    while(!q.empty()){
    	int nd=q.front();q.pop();
    	for(int i=1;i<=k;i++)
    		if(s[arr[nd]][i]=='1'){
    			if(l[nd][i] and umin(dis[l[nd][i]],dis[nd]+abs(l[nd][i]-nd)))
					q.push(l[nd][i]);
    			if(r[nd][i] and umin(dis[r[nd][i]],dis[nd]+abs(r[nd][i]-nd)))
					q.push(r[nd][i]);	
    		}
    }
    if(dis[n]==INF)dis[n]=-1;
    printf("%d\n",dis[n]);
	return 0;
}

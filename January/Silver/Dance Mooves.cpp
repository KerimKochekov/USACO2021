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
int arr[MAXN],a[MAXN],b[MAXN],ans[MAXN],mark[MAXN];
set<int>vis[MAXN],s;
int main(){
    //freopen("file.in", "r", stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)arr[i]=i,vis[i].insert(i);
    for(int i=0;i<k;i++)
    	scanf("%d%d",a+i,b+i),a[i]--,b[i]--;
    for(int i=0;i<k;i++){
    	int x=a[i%k],y=b[i%k];
    	swap(arr[x],arr[y]);
    	for(int j=0;j<2;j++){
	    	if(vis[arr[x]].find(y)==vis[arr[x]].end())
				vis[arr[x]].insert(y);
	    	swap(x,y);
	    }
    }
    for(int i=0;i<n;i++)
    	if(!mark[i]){
    		int to=i;s.clear();
    		do{
    			tr(it,vis[to])s.insert(*it);
    			mark[to]=1;to=arr[to];
			}while(to!=i);
    		do{
    			ans[to]=int(s.size());
				to=arr[to];
			}while(to!=i);
    	}
    for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}

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
char s[MAXN];
int arr[MAXN];
const int N=20;
int cnt[N][N],sz,all;
int dp[1<<N];
int rec(int mask){
	if(mask==all)return 0;
	int &ret=dp[mask];
	if(~ret)return ret;ret=INF;
	for(int i=0,cost;i<sz;i++)
		if(!(mask>>i&1)){
			cost=0;mask|=(1<<i);
			for(int j=0;j<sz;j++)
				if(mask>>j&1)
					cost+=cnt[i][j];
			umin(ret,rec(mask)+cost);
			mask^=(1<<i);
		}
	return ret;
}	
int main(){
    //freopen("file.in", "r", stdin);
    scanf("%s",s+1);
    int n=strlen(s+1);vector<char>v;
    for(int i=1;i<=n;i++)v.pb(s[i]);
    sort(all(v));v.erase(unique(all(v)),v.end());
    sz=int(v.size());assert(sz<=N);
    for(int i=1;i<=n;i++)arr[i]=lower_bound(all(v),s[i])-v.begin();
    for(int i=1;i<n;i++)
    	cnt[arr[i]][arr[i+1]]++;
    all=(1<<sz)-1;memset(dp,-1,sizeof dp);
	printf("%d\n",rec(0)+1);
	return 0;
}

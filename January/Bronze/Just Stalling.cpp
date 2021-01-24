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
ll dp[1<<20][20];
int n,a[20],b[20];
ll rec(int mask,int pos){
	if(pos==n)return 1;
	ll &ret=dp[mask][pos];
	if(~ret)return ret;ret=0;
	for(int i=0;i<n;i++)
		if(!(mask>>i&1) and a[i]<=b[pos])
			ret+=rec(mask|(1<<i),pos+1);	
	return ret;
}
int main(){
    //freopen("file.in", "r", stdin);
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	scanf("%d",a+i);
    for(int i=0;i<n;i++)
    	scanf("%d",b+i);
    printf("%lld\n",rec(0,0));
	return 0;
}

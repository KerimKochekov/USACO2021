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
int cnt[2];
int main(){
    //freopen("file.in", "r", stdin);
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&x),cnt[x%2]++;
    for(int x=n;x>=1;x--){
    	int even=(x+1)/2;
    	int odd=x/2;
    	if(odd<=cnt[1] and (cnt[1]%2)==(odd%2) and even<=cnt[0]+(cnt[1]-odd)/2)
    		return printf("%d\n",x)*0;
    }	
	return 0;
}

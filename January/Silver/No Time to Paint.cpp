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
const int N=26;
int pre[N][MAXN],suf[N][MAXN];
vector<int>v;
char s[MAXN];
int main(){
    //freopen("file.in", "r", stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);assert(n>1);
    for(int j=0;j<26;j++){
    	v.clear();
    	for(int i=1;i<=n;i++)
    		if(s[i]-'A'<j){
    			if(!v.empty()){
					pre[j][v[0]]++;
					suf[j][v.back()]++;
    			}
    			v.clear();
    		}
    		else{
    			if(s[i]-'A'==j)	
    				v.pb(i);
    		}
		if(!v.empty()){
			pre[j][v[0]]++;
			suf[j][v.back()]++;
		}
		for(int i=1;i<=n;i++)
			pre[j][i]+=pre[j][i-1];
		for(int i=n;i>=1;i--)
			suf[j][i]+=suf[j][i+1];
    }
    while(q--){
    	int l,r,ans=0;
		scanf("%d%d",&l,&r);l--;r++;
		for(int i=0;i<26;i++)
			ans+=pre[i][l]+suf[i][r];	
		printf("%d\n",ans);
    }
	return 0;
}


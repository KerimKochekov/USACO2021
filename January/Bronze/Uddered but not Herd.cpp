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
char s[26],t[1234];
int main(){
    //freopen("file.in", "r", stdin);
    scanf("%s",s);scanf("%s",t);int n=strlen(t);
    int pos=0,ans=1;
    for(int i=0;i<n;i++){pos++;if(pos==26)pos=0,ans++;
    	while(s[pos]!=t[i])
    		if(++pos==26)ans++,pos=0;
    }printf("%d\n",ans);
	return 0;
}

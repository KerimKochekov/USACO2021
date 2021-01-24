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
const int N=1e3+3;
int col[2][N],row[2][N];
int main(){
    //freopen("file.in", "r", stdin);
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++){
			scanf("%d",&x);
			col[i%2][j]+=x;	
			row[j%2][i]+=x;
    	}
    int a=0,b=0;
    for(int i=0;i<n;i++)
    	a+=max(col[0][i],col[1][i]);
    for(int i=0;i<n;i++)
    	b+=max(row[0][i],row[1][i]);
    printf("%d\n",max(a,b));
	return 0;
}

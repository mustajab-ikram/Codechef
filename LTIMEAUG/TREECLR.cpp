#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define tp top()
#define pp pop()
#define kk empty()
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define endl			'\n'
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_a(i,a,n) for(int i=a;i<n;i++)

void onlineJudge()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
}

template<typename ...Args>
void Read(Args&... args) {
    (cin >> ... >> args);
}

ll po(ll x, ll n ){ 
    ll ans=1;
     while(n>0){
        if(n&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
     }
     return ans;
}
/////////////////////////////////////////////////////////
/*
	Que.
	Given a tree containing NNN nodes.

Each node can be coloured using exactly one of the CCC colours. Find the number of colourings of the tree such that:

    All nodes in a path of length at most two have distinct colours.

As the answer can be huge, print it modulo (109+7)(10 ^ 9 + 7)(109+7).
*/
/////////////////////////////////////////////////////////

const ll MX = 2000005;
vector<vector<int>> tree;
int dgr[MX], par[MX], chl[MX], flag = -1;
vector<int> val,vis;



void dfs(int current, int parent)
{
    vis[current] = 1;
    int begin = parent;
    if(current == 1) {
    	begin = parent - 1;
    } else begin = parent - 2;
    for(auto it: tree[current]) {
    	if(vis[it] == 0) {
    		val[it] = begin;
    		dfs(it, parent);
    		begin--;
    	}

    }
    return;
}


/////////////////////////////////////////////////////////

void mainCode(int t) {
	// Write Your Code Here
	int N, C;
	Read(N, C);
	val.assign(N + 1, 1);
	vis.assign(N + 1, 0);
	tree.assign(N + 1, {});
	int u, v;
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> u >> v;
		tree[u].push_back(v); dgr[u]++;
		tree[v].push_back(u);	dgr[v]++;
	}
	val[1] = C;
	for (int i = 1; i <= N; ++i)
	{
		/* code */
		if(vis[i] == 0) dfs(i, C);
	}
	ll ans = 1;
	for (int i = 1; i <= N; ++i)
	{
		/* code */
		ans *= val[i]; ans %= mod;
	}
	cout << ans;
	if(t) 
	cout << endl;
} 

/////////////////////////////////////////////////////////
signed main()
{
    onlineJudge();
    int t = 1;
    // cin >> t;
    while(t--) {
    	mainCode(t);
    }
    return 0;
}
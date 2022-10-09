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

#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define endl			'\n'
 
 
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


/////////////////////////////////////////////////////////

void solve() {
	// Write Your Code Here
	int N, X, Y;
	Read(N, X, Y);

	ll ans = 0;
	ans += (2 * N) - 2;    // Horizontal + Vertical

	ans += N - 1 - abs(X - Y);        // Diagonal - / : Perpendicular Distance From Main Diagonal  

	ans += N - 1 - abs(X + Y - N - 1);        // Diagonal - \ : Perpendicular Distance From Main Diagonal 

	cout << ans;
} 

/////////////////////////////////////////////////////////
int main()
{
    onlineJudge();
    int t = 1;
    cin >> t;
    while(t--) {
    	solve();
    	cout << endl;
    }
    return 0;
}
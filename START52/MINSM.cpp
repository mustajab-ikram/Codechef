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
/*
    Que. Find the minimum possible sum (ie. A1+A2+⋯+AN) that you can achieve by,
	Choose any two indices i and j and replace either Ai or Aj with gcd⁡(Ai,Aj) and output that.
*/
/////////////////////////////////////////////////////////

void mainCode(int t) {
	// Write Your Code Here
	int N; cin >> N;
	ll first, restElements; cin >> first;
	for (int i = 1; i < N; ++i)
	{
		cin >> restElements;
		first = __gcd(first, restElements);
	}
	cout << first * N;

	if(t) 
	cout << endl;
} 

/////////////////////////////////////////////////////////
int main()
{
    onlineJudge();
    int t = 1;
    cin >> t;
    while(t--) {
    	mainCode(t);
    }
    return 0;
}
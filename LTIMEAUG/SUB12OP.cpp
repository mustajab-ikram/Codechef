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
#define rep(i,N) for(int i=0;i<N;i++)
#define rep_a(i,a,N) for(int i=a;i<N;i++)
#define rev(i,N) for(int i=N;i>1;i--)
#define int long long
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
Que.
	You are given NNN integers A1,A2,…,ANA_1, A_2, \ldots, A_NA1​,A2​,…,AN​.

You can perform the following operation any number of times:

    Select any index iii such that 1≤i≤(N−1)1 \le i \le (N-1)1≤i≤(N−1);
    Subtract 111 from AiA_iAi​ and 222 from Ai+1A_{i+1}Ai+1​.

Find the smallest possible value of ∣A1∣+∣A2∣+…+∣AN∣|A_1| + |A_2| + \ldots + |A_N|∣A1​∣+∣A2​∣+…+∣AN​∣ you can achieve after performing any number of given operations.
*/
/////////////////////////////////////////////////////////
const ll MX = 2000005;

ll arr[MX];
void mainCode(int t) {
	// Write Your Code Here
	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	if(N == 1) cout << abs(arr[1]);
	else {
		rev(i, N) {
			if(arr[i] > 0) {
				arr[i - 1] -= arr[i] / 2;
				arr[i] = arr[i] % 2;
				if(arr[i] == 1 and (arr[i - 1] % 2 == 1) || ((i == 2) and arr[1] > 0)) {
					arr[i] = -1;
					arr[i - 1]--;
				}
			}
		}
		ll ans = 0;
		rep_a(i, 1, N + 1) ans += abs(arr[i]);
		cout << ans;
	}
	if(t) 
	cout << endl;
} 

/////////////////////////////////////////////////////////
signed main()
{
    onlineJudge();
    int t = 1;
    cin >> t;
    while(t--) {
    	mainCode(t);
    }
    return 0;
}
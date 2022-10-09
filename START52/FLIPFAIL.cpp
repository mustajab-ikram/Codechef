#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <iomanip>
#include<climits>

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

void mainCode(int t) {
	// Write Your Code Here
	string str; cin >> str; int size = str.size();
	mk(helperArr, size, int);
	mk(helperArrB, size + 1, int);

	for (int i = 0; i < size; ++i)
	{
		helperArr[i] = str[i] - '0';
		helperArrB[i + 1] = helperArr[i];
	}
	for (int i = 1; i < size + 1; ++i)
	{
		helperArrB[i] += helperArrB[i - 1]; 
	}
	int mm = helperArrB[size - 1] - helperArrB[0];

	int num = INT_MAX;
	for(int i = 1; i <= size; ++i) {
    if(size - i - (helperArrB[size] - helperArrB[i]) > helperArrB[i] - helperArrB[0]) continue;
    	num = min(num, size - i - (helperArrB[size] - helperArrB[i]) + (helperArrB[i] - helperArrB[0]) - (size - i - (helperArrB[size] - helperArrB[i])) - helperArrB[(helperArrB[i] - helperArrB[0]) -(size - i - ((helperArrB[size] - helperArrB[i])))] - helperArrB[0]);
  	}
  	cout << num;
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
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

void mainCode(int t) {
    int board[8][8] = {0};	
    vector<pair<int, int>> pos;
    
	// Write Your Code Here
	int A, B; Read(A, B); A--; B--;
	board[A][B] = 1;
	int positions[8][2] = 
						{
							{1, 2},
							{1, -2},
							{-1, 2},
							{-1, -2},
							{2, 1},
							{2, -1},
							{-2, 1},
							{-2, -1},
						};
	int X, Y;
	for (int i = 0; i < 8; ++i)
	{
		X = positions[i][0] + A; 
		Y = positions[i][1] + B;
		if(X < 0 or Y < 0 or X > 7 or Y > 7) continue;
		else {
			pos.push_back({X, Y});
		}
	}
	int till = pos.size(), m, n, count = 0;
	sort(all(pos));
	for (int i = 0; i < till; i++)
	{
		if(count == 2) break;
		m = pos[i].ff; n = pos[i].ss; 
		if(A == 0 and B == 0 or B == 0 and A == 7 or A == 7 and B == 7 or B == 7 and A == 0) till = 1;
		else if(A == 0 or B == 0 or A == 7 or B == 7) till = 2;
		else if(A == 1 or B == 1 or A == 6 or B == 6) m;
		else i += 6;
		board[m][n] = 2; count++;
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

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
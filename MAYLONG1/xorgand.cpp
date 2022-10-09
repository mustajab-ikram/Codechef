#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define endl "\n"

void onlineJudge()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL) ,cout.tie(NULL);
	onlineJudge();

	int t = 1; 
	cin >> t;
	while(t--) {
		int N; cin >> N;
		int arr[N], dp[33] = {0}; 
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
			dp[(int)log2(arr[i])]++;
		}
		int Q; cin >> Q;
		int L, R, X;
		while(Q--) {
			cin >> L >> R >> X;

			cout << R - L + 1 - dp[(int)log2(X)];

			if(Q) cout << endl;
		}

		if(t) cout << endl;
	}
}
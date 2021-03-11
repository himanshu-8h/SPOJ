// Created by  himanshu8h
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define all(a) (a).begin(), (a).end()
#define rev(a) reverse(all(a))

using namespace std;
using ll = long long;
int dp[201][201][2];
int nn, mm;
void init(int n, int m) {
	nn = n;
	mm = m;
	rep(i, 201) rep(j, 201) rep(k, 2)	dp[i][j][k] = INT_MIN;
}
bool isValid(int i, int j) {
	if (i >= 0 and i < nn and j >= 0 and j < mm )
		return 1;
	return 0;
}
int solve(vector<vector<int>> &v, int i = 0, int j = 0, int k = 0) {

	if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

	int sameRow = INT_MIN, down = INT_MIN;
	if (k == 0 and isValid(i, j + 1) and v[i][j + 1] != -1)
		sameRow = solve(v, i, j + 1, k);
	if (k == 1 and isValid(i, j - 1) and v[i][j - 1] != -1)
		sameRow = solve(v, i, j - 1, k);
	//down
	if (isValid(i + 1, j) and v[i + 1][j] != -1)
		down = solve(v, i + 1, j, 1 - k);

	int currans = max(sameRow, down);
	if (currans == INT_MIN) currans = 0;
	dp[i][j][k] = v[i][j] + currans;
	return dp[i][j][k];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		init(n, m);
		vector< vector<int> > v(n, vector<int>(m));
		rep(i, n) {
			rep(j, m) {
				char c;
				cin >> c;
				if (c == '#') v[i][j] = -1;
				else if (c == 'T') v[i][j] = 1;
				else v[i][j] = 0;
			}
		}
		if (v[0][0] != -1)
			cout << solve(v) << '\n';
		else cout << "0\n";
	}
	return 0;
}
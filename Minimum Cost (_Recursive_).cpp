#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;


int dp[1001][1001];

int len1,len2;
string s1,s2;

int lcs(int i, int j)
{
	if(i==len1 || j == len2)return dp[i][j]=0;

		if(dp[i][j]!=-1)return dp[i][j];

	if(s1[i]==s2[j])
	{
		dp[i][j] = 1+lcs(i+1,j+1);
		return dp[i][j];
	}
	else
	{
		dp[i][j] = max(lcs(i,j+1),lcs(i+1,j));
		return dp[i][j];
	}
}


void solve()
{
	while(1){
		cin >> s1;
		if(s1=="#")break;
		cin >> s2;
		len2 = s2.size();
		len1 = s1.size();
		memset(dp,-1,sizeof(dp));

		int p = lcs(0,0);
		ll ans = (len1-p)*15 + (len2-p)*30;
		cout << ans << endl;
		s1.clear();
		s2.clear();
    }

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase=1;
	//cin >> testcase;
	while(testcase--)
		solve();
	return 0;
}
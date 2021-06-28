#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int len1,len2;
string s1,s2;

string dp[105][105];

int cnt = 0;

string lcs(int i, int j)
{
	string tem;
	if(i==len1 || j == len2)
	{
		return "";
	}
	if(dp[i][j]!="!")return dp[i][j];

	if(s1[i]==s2[j])
	{
		tem+=s1.substr(i,1);
		tem += lcs(i+1,j+1);
		dp[i][j] = tem;
		return dp[i][j];
	}
	else
	{
		string p = lcs(i,j+1);
		string q = lcs(i+1,j);
		if(p.size()>q.size())return dp[i][j]=p;
		if(q.size()>p.size())return dp[i][j]=q;
		else return dp[i][j] = min(p,q);
	}
}





void solve(int test)
{
	cin >> s1 >> s2;
	len2 = s2.size();
	len1 = s1.size();
	for(int i=0;i<=101;i++)
	{
		for(int j=0;j<=101;j++)
		{
			dp[i][j]="!";
		}
	}
	string p = lcs(0,0);
	cout << "Case " << test << ": ";
	if(p.size()==0)
             cout << ":(\n";
	else
             cout << p << endl;
	s1.clear();
	s2.clear();

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase=1;
	cin >> testcase;
	for(int i=1;i<=testcase;i++)
		solve(i);
	return 0;
}
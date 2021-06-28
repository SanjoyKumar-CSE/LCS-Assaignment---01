#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

void solve(int t)
{
	string dp[103][103];

	int len1,len2;
	string s1,s2;
		cin >> s1;
		cin >> s2;
		len2 = s2.size();
		len1 = s1.size();

		for(int i=0;i<=len1;i++)
		{
			for(int j=0;j<=len2;j++)
			{
				if(i==0 || j==0)
				{
					dp[i][j]="";
					continue;
				}

				if(s1[i-1]==s2[j-1])dp[i][j] = dp[i-1][j-1] + s1.substr(i-1,1);
				else
				    {
				    	string p = dp[i][j-1];
				    	string q = dp[i-1][j];
				    	if(p.size() > q.size()) dp[i][j] = p;
				    	else if(p.size() < q.size()) dp[i][j] = q;
				    	else dp[i][j] = min(p,q);

				    }
			}
		}
		cout << "Case " << t << ": ";
		string p = dp[len1][len2];
		if(p.size()==0) cout << ":(\n";
		else
		{
			cout << p;
			cout << endl;
		}
		
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
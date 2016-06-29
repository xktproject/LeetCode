class Solution {
public:
    const int MAX = 1000;
    string longestPalindrome(string s) 
   {
	bool dp[MAX][MAX] = {0};
        int nLength = 1;
        int nStart = 0;
 	int j = 0;
	for(int i = 0; i < MAX; i++)
	      dp[i][i] = true;
	for(int len = 2; len <= s.length(); len++)
	{
	    for(int i = 0; i+len <= s.length();i++)     	
	    {
		j= i + len -1;
		if(s[i] == s[j] && (len == 2 || dp[i+1][j-1]))
		{
		   dp[i][j] = true;
		   nStart = i;
                   nLength = len;
		}
		else
		   dp[i][j] = false;
	    }
        }
	return s.substr(nStart, nLength);
    }
};
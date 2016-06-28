class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
            
        int nMax = 0;
        int nTmp = 0;
        int nIndex = 0;
        int nFlag[256];
	for(int i = 0; i < 256; i++)
             nFlag[i] = -1;
	
	for(int i = 0; i < s.length(); i++)
	{
	     nIndex = s[i];
	     if(nFlag[nIndex] >= 0)
	     {
		 nMax = nMax >= nTmp? nMax:nTmp;
		 nTmp = i-nFlag[nIndex]; 
	         for(int j = 0; j < 256; j++)
                    if(nFlag[j] < nFlag[nIndex])
			nFlag[j] = -1;
	      }
             else
                nTmp++;
		
	     nFlag[nIndex] = i;
	}	
	nMax = nMax >= nTmp? nMax:nTmp;
	return nMax;
    }
};
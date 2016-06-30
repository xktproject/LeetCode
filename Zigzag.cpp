class Solution {
public:
    string convert(string s, int numRows) 
   {
	string strRes;
	vector<string> vecItem(numRows);
   	int nEnd = numRows - 2;     
	for(int i = 0; i < s.length(); )
	{
	    for(int j = 0; j < numRows && i < s.length(); j++)
		vecItem[j] += s[i++];
		
	    for(int j = nEnd; j > 0 &&  i < s.length(); j--)
		vecItem[j] += s[i++];
	}
	for(int i = 0; i < numRows; i++)
	   strRes += vecItem[i];
	
	return strRes;
    }
};
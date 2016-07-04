class Solution {
public:
    int myAtoi(string str) 
   {
        if(str.empty())
		return 0;
	int s=str.find_first_not_of(" ");
	int e=str.find_last_not_of(" ");
	string strTmp = str.substr(s,e-s+1);;
	
   	bool bNegative = ('-' == strTmp [0]);
	
	if('-' == strTmp [0] || '+' == strTmp [0])
	    strTmp = strTmp.substr(1);
	
	long long llRes = 0;
	int i = 0;
        while(i < strTmp.length())
	{
	    if(strTmp[i] > '9' || strTmp[i] < '0')
		break;
	    llRes = llRes * 10 + strTmp[i]-'0';
            
	    if(!bNegative && llRes > 2147483647)
		return 2147483647;
       	    if(bNegative && llRes > 2147483648)
		return -2147483648;
	
	    i++;    
	}
	
        return bNegative? -llRes:llRes;
    }
};
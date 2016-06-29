class Solution {
public:
    int reverse(int x) 
    {
    	int num = x>0?x:-x;
        long long tmp = 0, res = 0;
	while(num>0)
	{
	   tmp = num % 10;
           num /= 10; 
	   res *= 10;
           res += tmp;          
	}
	if(res > 2147483647)
		return 0;
        return x > 0? res:-res;    
    }
};
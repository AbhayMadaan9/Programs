//https://www.codingninjas.com/codestudio/problems/megaprime-numbers_893339?leftPanelTab=1
bool isprime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i*i<=n; i+=6)
    {
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}

int countMegaPrimeNumber(int left, int right) {
    int count = 0;
    for(int i = left; i <= right; i++)
    {
        if(isprime(i)) 
        {
            string num = to_string(i);
            bool x = false;
            for(auto &j: num)
            {
                if(isprime(j-'0')) continue;
                else {x = true; break;}
            }
            if(!x) count++;
        }
    }   
    return count;
}

long long Pow(int X, int N)
{
    if(N == 0 || X == 0) return 1;
   if(N > 0) return X * Pow(X, N-1);
}
#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-msb-in-o-1_1112570
//approch on new copy
int findMSB(int n){
	if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}
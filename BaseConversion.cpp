#include <bits/stdc++.h> 
//To convert a number from base B to base 10, we need 
//to multiply each digit by the corresponding power of B 
//and add them together. If any digit is greater than or 
//equal to B, then the input is invalid and we should return -1.
//https://www.codingninjas.com/codestudio/problems/base-conversion_1171187?leftPanelTab=0
int baseConversion(string &n, int b)
{
	  int len = n.length();
    int decimal = 0;
    int power = 0;
    
    for(int i = len - 1; i >= 0; i--) {
        int digit;
        if(isdigit(n[i])) {
            digit = n[i] - '0';
        } else {
            digit = n[i] - 'A' + 10;
        }
        
        if(digit >= b) {
            return -1; // impossible to convert to base 10
        }
        
        decimal += digit * pow(b, power);
        power++;
    }
    
    return decimal;
}

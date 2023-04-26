#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/reverse-vowels-in-a-string_1231000?leftPanelTab=1
bool check(char chr)
{
    switch(chr)
    {
        case 'a':
        return true;
        break;

         case 'e':
        return true;
        break;

         case 'i':
        return true;
        break;

         case 'o':
        return true;
        break;

         case 'u':
        return true;
        break;
        
        default:
        return false;
        break;
    }
}
string reverseVowels(string &s)
{
    int i = 0, j = s.length()-1;
    while(i < j)
    {
        if(check(s[i]) and check(s[j])) {swap(s[i], s[j]); i++; j--;}
        else if(check(s[i]) and !check(s[j])) j--;
        else i++;
    }  
    return s;
}
#include <bits/stdc++.h> 
//logic on copy
//https://www.codingninjas.com/codestudio/problems/valid-word-abbreviations_1171044?leftPanelTab=1
bool validAbbreviation (string &str, string &abbr) {
    if(str.length() == 0 or abbr.length() == 0) return false;
	int ind1 = 0;
    int ind2 = 0;

    while(ind1 < str.length() and ind2 < abbr.length())
    {
        if(isdigit(abbr[ind2]))
        {
            //check leading 0
            if(abbr[ind2] == '0') return false;
            int total = 0;
            while(ind2 < abbr.length() and isdigit(abbr[ind2])){
                total = total*10 + abbr[ind2]-'0';
                ind2++;
            }
            ind1 += total;
        }
        else if(abbr[ind2] != str[ind1]) return false;
        else{
            ind1++;
            ind2++;
        }
    }
    return (ind1 == str.length() and ind2 == abbr.length());
}
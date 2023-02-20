#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/multiply-strings_982763?leftPanelTab=0
string multiplyStrings(string a , string b) {
    int n = a.length();
    int m = b.length();
    vector<int> res(n+m, 0);  // corrected initialization of res vector
    // a is below b
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            int product = (a[i]-'0') * (b[j] - '0');
            product += res[i+j+1];
            res[i+j+1] = product%10;
            res[i+j] += product/10;
        }
    }
    string ans = "";
    for(int i = 0; i < res.size(); i++) {
        if(ans.empty() && res[i] == 0) continue;  // skip leading zeros
        ans += char(res[i] + '0');  // convert digit to character
    }
    return ans.empty() ? "0" : ans;
}

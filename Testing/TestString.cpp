#include <bits/stdc++.h>
using namespace std;

// approch 1 Genrating all the possibe strings by removing the current index bracket or skipping the current index bracket.
// approch 2 (idea from given approch of this solutions which appears on a page before enter to this page)using BFS

bool isDuplicate(unordered_map<string, int> &ump, string str)
{
    if (ump.find(str) == ump.end())
    {
        ump[str]++;
        return false;
    }
    else
    {
        return true;
    }
}

bool isValid(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            cnt++;
        }
        if (str[i] == ')')
        {
            cnt--;
        }
    }
    if (cnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<string> minRemovaltoMakeStringValid(string &str)
{
    vector<string> ans;
    queue<pair<int, string>> q;
    q.push({0, str});
    unordered_map<string, int> ump;
    ump[str]++;
    while (!q.empty())
    {
        auto cur = q.front();
        int ind = cur.first;
        string tempStr = cur.second;
        cout<<tempStr<<endl;
        q.pop();
        if (isDuplicate(ump, tempStr))
        {
            continue;
        }
        if (isValid(tempStr))
        {
            ans.push_back(tempStr);
        }
        else
        {
            if (ind < tempStr.size() and (tempStr[ind] == '(' or tempStr[ind] == ')'))
            {
                // remove bracket
                string removed = tempStr.substr(0, ind) + tempStr.substr(ind + 1);
                cout<<removed<<endl;
                q.push({ind, removed});
                // keep the bracket
                q.push({ind + 1, tempStr});
            }
        }
    }
    return ans;
}
char kThCharaterOfDecryptedString(string s, long long k)
{
    string decrypted;
    int i = 0;
    while(i < s.length())
    {
        string temp = "";
        if(!isdigit(s[i]))
        {
            while(!isdigit(s[i]))
            {
                temp += s[i];
                i++;
            }
        }
        else{
            string num = "";
            while(isdigit(s[i]))
            {
                num += s[i];
                i++;
            }
            int len = stoi(num);
            while(len--)
            {
                decrypted.append(temp);
            }
        }
    }
    return decrypted[k-1];
}
void print(vector<string> ans)
{
    for (const auto &i : ans) cout << i << endl;
}
int main()
{
    string str = "av5g2";
//    vector<string> ans = minRemovaltoMakeStringValid(str);
    char kthChar = kThCharaterOfDecryptedString(str, 6);
    cout<<kthChar<<endl;
   // print(ans);
    return 0;
}
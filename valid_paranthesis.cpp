//https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=1
bool isValidParenthesis(string expression)
{
    stack<char>s;
    for(int i = 0; i < expression.size(); i++)
    {
        char ele = expression[i];
        
        if(ele == '{' or ele == '(' or ele == '[')
        {
            s.push(ele);
        }
        else
        {
            if(s.empty()) return false;
            else
            {
                int topi = s.top();
                if((ele == '}' and topi == '{') or (ele == ')' and topi == '(') or(ele == ']' and topi == '[') )
                {
                    s.pop();
                }
                else return false;
            }
            
        }
    }
    return s.empty();
}
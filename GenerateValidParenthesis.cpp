//https://www.codingninjas.com/studio/problems/generate-all-parenthesis_920445
void solve(vector<string>& ans, string str, int left, int right) {
    if (right == 0 && left == 0) {
        ans.push_back(str);
        return;
    }

    if (left > 0) {
        solve(ans, str + "(", left - 1, right);
    }
    if (right > 0 && right > left) {
        solve(ans, str + ")", left, right - 1);
    }
}

vector<string> validParenthesis(int n) {
    vector<string> ans;
    solve(ans, "", n, n);
    return ans;
}

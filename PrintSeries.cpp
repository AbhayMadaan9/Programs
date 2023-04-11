//https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148627/offering/1792822?leftPanelTab=1
void solve1(int n, int k, vector<int> &ans, int &s) {

  if (n <= 0) {

    s = n;

    return;
  }

  ans.push_back(n);

  solve1(n - k, k, ans, s);
}

void solve2(int n, int k, int temp, vector<int> &ans) {

  if (temp == n) {

    ans.push_back(temp);

    return;
  }

  ans.push_back(temp);

  solve2(n, k, temp + k, ans);
}

vector<int> printSeries(int n, int k)

{

  int temp;

  vector<int> ans;

  solve1(n, k, ans, temp);

  solve2(n, k, temp, ans);

  return ans;
}
// void solve(int x, int n, int k, vector<int>&ans)
// {
//     if(x == n) {ans.push_back(n);return;}
//     ans.push_back(x);
//    if(x > 0) solve(x-k, n, k, ans);
//      else solve(x+k, n, k, ans);
// }
// vector<int> printSeries(int n, int k)
// {
//     vector<int>ans;
//     ans.push_back(n);
//     solve(n-k, n, k, ans);
//     return ans;
// }
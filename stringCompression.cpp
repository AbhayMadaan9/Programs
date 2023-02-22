//https://www.codingninjas.com/codestudio/problems/compress-the-string_526?leftPanelTab=1
string getCompressedString(string &input) {
    string ans = "";
    for(int i = 0; i < input.length(); i++)
    {
        ans += input[i];
        int count = 0;
        while(input[i] == input[i+1]) {count++; i++;}
        if(count > 0) ans += to_string(count + 1);
    }
    return ans;
}

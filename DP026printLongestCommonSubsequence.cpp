//  print longest common sequence

#include<bits/stdc++.h>
using namespace std;

void lcs(string s, string t){
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for (int i=1; i<=n; i++) {
    for (int j = 1; j<=m; j++){
      if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  int len = dp[n][m];
  string ans = "";
  for (int i=0; i<len; i++){
    ans += '$';
  }

  int index = len-1;
  int i = n, j = m;
  while (i>0 && j>0){
    if(s[i-1] == t[j-1]){
      ans[index] = s[i-1];
      index--;
      i--, j--;
    }
    else if (dp[i-1][j] > dp[i][j-1]){
      i--;
    }
    else j--;
  }
  cout << ans;
}

int main() {

  string s1 = "abcde";
  string s2 = "bdgek";

  cout << "The Longest Common Subsequence is ";
  lcs(s1, s2);
}
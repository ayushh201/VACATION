class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string &s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i] == s[j]){
            return t[i][j] = 2+solve(i+1,j-1,s);
        }
        return t[i][j] = max(solve(i+1,j,s),solve(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};



class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> t(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            t[i][i] = 1;
        }
        for(int length=2;length<=n;length++){
            for(int i=0;i+length-1<n;i++){
                int j=i+length-1;
                if(s[i] == s[j]){
                    t[i][j] = 2+t[i+1][j-1];
                }else{
                    t[i][j] = max(t[i+1][j],t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};

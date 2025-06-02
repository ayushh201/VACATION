class Solution {
    private:
    void solve(int i,string& s,vector<string>& currPartition,vector<vector<bool>>& t,vector<vector<string>>& result){
        if(i == s.length()){
            result.push_back(currPartition);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(t[i][j] == true){
                currPartition.push_back(s.substr(i,j-i+1));
                solve(j+1,s,currPartition,t,result);
                currPartition.pop_back();
            }
        }
    }
    public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) t[i][i] = true;
        for(int length=2;length<=n;length++){
            for(int i=0;i<n-length+1;i++){
                int j = i+length-1;
                if(s[i] == s[j]){
                    if(length == 2){
                        t[i][j] = true;
                    }else{
                        t[i][j] = t[i+1][j-1];
                    }
                }
            }
        }
        vector<vector<string>> result;
        vector<string> currPartition;
        solve(0,s,currPartition,t,result);
        return result;
    }
};

#include <bits/stdc++.h>
using namespace std;

string findLongestSubstring(string &s){
    int n = s.length();
    int sp = 0, maxLength = 0;
    vector<vector<bool>> t(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        t[i][i] = true;
        maxLength = 1;
    }
    for(int length=2;length<=n;length++){
        for(int i=0;i+length-1<n;i++){
            int j=i+length-1;
            if(length==2 && s[i]==s[j]){
                t[i][j] = true;
                maxLength = 2;
                sp = i;
            }else if(s[i]==s[j] && t[i+1][j-1]){
                t[i][j] = true;
                if(j-i+1 > maxLength){
                    maxLength = j-i+1;
                    sp = i;
                }
            }else{
                t[i][j] = false;
            }
        }
    }
    return s.substr(sp,maxLength);
}

int main()
{
    string s;
    cin>>s;
    string result = findLongestSubstring(s);
    cout<<result.length()<<" "<<result<<endl;
    return 0;
}

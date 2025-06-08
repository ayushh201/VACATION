class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1;i<=9;i++){
            solve(i,n,result);
        }
        return result;
    }

private:
    void solve(int currentNumber, int limit,
                                vector<int>& result) {
        if(currentNumber > limit) {
            return;
        }
        result.push_back(currentNumber);
        for(int append=0;append<=9;append++){
            int newNumber = (currentNumber*10)+append;
            if(newNumber > limit) return;
            solve(newNumber,limit,result);
        }
    }
};

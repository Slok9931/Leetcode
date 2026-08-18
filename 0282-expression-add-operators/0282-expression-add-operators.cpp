class Solution {
public:
    void solve(vector <string> &res, string num, int target, int index, string path, long long curr, long long prev){
        if(index == num.size()){
            if(curr == target) res.push_back(path);
            return;
        }
        for(int j=index;j<num.size();j++){
            if(j > index && num[index] == '0') break;
            string s = num.substr(index, j - index + 1);
            long long n = stoll(s);
            if(index == 0) solve(res, num, target, j+1, s, n, n);
            else{
                solve(res, num, target, j+1, path+"+"+s, curr+n, n);
                solve(res, num, target, j+1, path+"-"+s, curr-n, -n);
                solve(res, num, target, j+1, path+"*"+s, curr-prev+prev*n, prev*n);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector <string> res;
        solve(res, num, target, 0, "", 0, 0);
        return res;
    }
};

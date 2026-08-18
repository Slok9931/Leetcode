class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        string temp;
        while(i<s.size()){
            if(temp.size()==0||temp.back()!=s[i]){
                temp.push_back(s[i]);
                }
            else
            temp.pop_back();
            i++;
        }
        return temp;
    }
};

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack <int> s;
        queue <int> q;
        reverse(sandwiches.begin(), sandwiches.end());
        for(int i=0;i<students.size();i++){
            s.push(sandwiches[i]);
            q.push(students[i]);
        }
        int rotation = 0;
        while(!q.empty()){
            if(q.front() == s.top()){
                q.pop();
                s.pop();
                rotation = 0;
            }
            else{
                int temp = q.front();
                q.pop();
                q.push(temp);
                rotation++;
            }
            if(rotation == q.size()) break;
        }
        return q.size();
    }
};

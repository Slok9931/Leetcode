class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum = 0;
        for(int i=0;i<target.size();i++){
            sum += target[i];
            pq.push(target[i]);
        }
        long long rem, x, maxi;
        while(pq.top() != 1){
            maxi = pq.top();
            pq.pop();
            rem = sum - maxi;
            if(rem == 0) return false;
            x = maxi % rem;
            if(x == 0){
                if(rem == 1) return true;
                else return false;
            }
            if(rem <= 0 || rem >= maxi) return false;
            pq.push(x);
            sum = rem + x;
        }
        return true;
    }
};

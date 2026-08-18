class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int sum = 0;
        
        for (const string& op : operations) {
            if (op == "C") {
                sum -= score.back();
                score.pop_back();
            } 
            else if (op == "D") {
                int lastScore = score.back();
                score.push_back(2 * lastScore);
                sum += 2 * lastScore;
            } 
            else if (op == "+") {
                int lastScore = score.back();
                int secondLastScore = score[score.size() - 2];
                score.push_back(lastScore + secondLastScore);
                sum += lastScore + secondLastScore;
            } 
            else {
                int points = stoi(op);
                score.push_back(points);
                sum += points;
            }
        }
        
        return sum;
    }
};

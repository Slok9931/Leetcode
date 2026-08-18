class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        for (int a : asteroids) {
            bool destroyed = false;
            while (!s.empty() && a < 0 && s.top() > 0) {
                if (abs(a) > s.top()) {
                    s.pop();
                } else if (abs(a) == s.top()) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed && (a > 0 || s.empty() || s.top() < 0)) {
                s.push(a);
            }
        }

        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

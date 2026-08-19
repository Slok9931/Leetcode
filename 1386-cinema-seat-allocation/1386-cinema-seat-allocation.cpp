class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, bitset<10>> rows;
        for (auto &seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1] - 1;   
            rows[r].set(c);
        }
        int total = 2 * n;
        bitset<10> maskL, maskR, maskMid;
        for (int i = 1; i <= 4; i++) maskL.set(i);   
        for (int i = 5; i <= 8; i++) maskR.set(i);    
        for (int i = 3; i <= 6; i++) maskMid.set(i);
        int idx = 0;
        for (auto &[row, b] : rows) {
            bool l = (maskL & b).none();
            bool r = (maskR & b).none();
            if (l && r) {
                continue;
            }
            if (l || r || (maskMid & b).none()) {
                total--;
            } else {
                total -= 2;
            }
        }
        return total;
    }
};
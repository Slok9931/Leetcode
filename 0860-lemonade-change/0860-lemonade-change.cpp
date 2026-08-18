class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i = 0, coin5 = 0, coin10 = 0, coin20 = 0;
        while(i < bills.size()){
            if(bills[i] == 5) coin5++;
            else if(bills[i] == 10){
                coin10++;
                if(coin5 > 0) coin5--;
                else return false;
            }
            else{
                coin20++;
                if(coin10 > 0 && coin5 > 0){
                    coin10--;
                    coin5--;
                }
                else if(coin5 > 2) coin5 -= 3;
                else return false;
            }
            i++;
        }
        return true;
    }
};

class Solution {
public:
    string solve(int num){
        string digit[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string ans = "";
        if(num >= 100) ans += digit[num/100] + " Hundred ";
        num %= 100;
        if(num > 9 && num < 20) ans += teen[num - 10] + " ";
        else{
            if(num >= 20) ans += tens[num/10] + " ";
            num %= 10;
            if(num > 0) ans += digit[num] + " ";
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string temp[] = {"Thousand", "Million", "Billion"};
        string ans = solve(num % 1000);
        num /= 1000;
        for(int i=0;i<3;i++){
            if(num > 0 && num % 1000 > 0) ans = solve(num % 1000) + temp[i] + " " + ans;
            num /= 1000;
        }
        return ans.empty() ? ans : ans.substr(0, ans.size()-1);
    }
};

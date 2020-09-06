class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() <= 0) return true;
        int five = 0, ten = 0;
        for (int bill: bills) {
            if (bill == 5) {
                five++;
            }
            if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            if (bill == 20) {
                if (ten > 0 && five > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

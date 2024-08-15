class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coins = {0, 0, 0};
        
        for(int bill : bills){
            if(bill == 5){
                coins[0] += 1;
            }else if(bill == 10){
                if(coins[0] >= 1){
                    coins[0] -= 1;
                    coins[1] += 1;
                }else{
                    return false;
                }
            }else if(bill == 20){
                if(coins[1] >= 1 && coins[0] >= 1){
                    coins[1] -= 1;
                    coins[0] -= 1;
                    coins[2] += 1;
                }else if(coins[0] >= 3){
                    coins[0] -= 3;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
};
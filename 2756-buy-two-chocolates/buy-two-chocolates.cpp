class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int lowest = 101, secondLowest = 101;
        for(int price : prices){
            if(price <= lowest){
                secondLowest = lowest;
                lowest = price;
            }
            else{
                secondLowest = min(secondLowest, price);
            }
        }

        return lowest + secondLowest <= money ? money - lowest - secondLowest : money;
    }
};
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1){
            return n;
        }
        return floor(sqrt(n));
    }
};
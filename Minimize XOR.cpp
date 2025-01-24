class Solution {
public:

    int countSetBits(int num){
        int count = 0;
        while(num > 0){
            num &= (num - 1);
            count++;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int x = countSetBits(num1);
        int y = countSetBits(num2);
        if(x == y){
            return num1;
        }else if(x > y){
            for(int i = 0; i < 31; i++){
                if((1 << i) & num1){ // Returns any positive value, not necessary it should be 1
                    num1 &= ~(1 << i);
                    x--;
                }
                if(x == y) break;
            }
            return num1;
        }else if(x < y){
            for(int i = 0; i < 31; i++){
                if(((1 << i) & num1) == 0){
                    num1 |= (1 << i);
                    x++;
                }
                if(x == y) break;
            }
            return num1;
        }
        return -1;
    }
};

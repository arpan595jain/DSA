class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while( a !=0 || b!=0 || c!=0){ // run loop till any number become zero
            if((c & 1) == 1){// right most bit(MSB) == 1
                if((a & 1) == 0 && (b & 1) == 0 ){ 
                    flips++;
                }
            }
            if((c & 1) == 0){ // MSB == 0
                if((a & 1) == 1 && (b & 1) == 1 ){ // we have to flips both a & b 
                    flips += 2;//xor rule
                }
                else if((a & 1) == 1 || (b & 1) == 1){
                     flips++;
                }
            }
            a >>= 1; 
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};

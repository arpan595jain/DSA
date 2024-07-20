class Solution {
public:
    string losingPlayer(int x, int y) {
        int possibleTurns = min(x, y / 4);
        if (possibleTurns % 2 == 1) {
            return "Alice";
        } else {
            return "Bob";
        }
    
    }
};

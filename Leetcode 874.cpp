class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        // Store obstacles in a set for O(1) lookup
        std::unordered_set<std::string> obs;
        for (const auto& obstacle : obstacles) {
            obs.insert(std::to_string(obstacle[0]) + "," + std::to_string(obstacle[1]));
        }

        // Direction vectors for [N, E, S, W]
        std::vector<std::vector<int>> directionVectors = {
            {0, 1},   // North -> +Y direction
            {1, 0},   // East -> +X direction
            {0, -1},  // South -> -Y direction
            {-1, 0}   // West -> -X direction
        };

        // Map for changing directions
        std::vector<std::vector<int>> dirChangeMap = {
            {3, 1}, // N -> Left: W (index 3), Right: E (index 1)
            {0, 2}, // E -> Left: N (index 0), Right: S (index 2)
            {1, 3}, // S -> Left: E (index 1), Right: W (index 3)
            {2, 0}  // W -> Left: S (index 2), Right: N (index 0)
        };

        int currDirection = 0; // Start facing North
        int x = 0, y = 0;
        int maxDist = 0;

        for (int command : commands) {
            if (command > 0) {
                int dx = directionVectors[currDirection][0];
                int dy = directionVectors[currDirection][1];
                for (int i = 0; i < command; i++) {
                    int nextX = x + dx;
                    int nextY = y + dy;
                    if (obs.find(std::to_string(nextX) + "," + std::to_string(nextY)) != obs.end()) {
                        break;
                    }
                    x = nextX;
                    y = nextY;
                }
                maxDist = std::max(maxDist, x * x + y * y);
            } else {
                currDirection = dirChangeMap[currDirection][command == -1 ? 1 : 0];
            }
        }

        return maxDist;
    }
};

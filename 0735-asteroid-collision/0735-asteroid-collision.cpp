class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack; // Stores surviving asteroids
        for (int& a : asteroids) {
            // Collision happens if stack top is moving right (>) and current is moving left (<)
            while (!stack.empty() && a < 0 && stack.back() > 0) {
                int diff = a + stack.back(); // Compare sizes
                if (diff < 0) {
                    stack.pop_back(); // Top asteroid destroyed, keep checking current 'a'
                } else if (diff > 0) {
                    a = 0; // Current asteroid 'a' destroyed
                } else {
                    a = 0; // Both destroyed
                    stack.pop_back();
                }
            }
            // If current asteroid survived, add it to the stack
            if (a != 0) {
                stack.push_back(a);
            }
        }
        return stack;
    }
};


class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        // Pair position and speed
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        // Sort by position in descending order (closest to target first)
        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double max_time = 0.0;

        // Iterate through the sorted cars
        for (const auto& car : cars) {
            // time = (target - position) / speed
            double time = static_cast<double>(target - car.first) / car.second;
            
            // If this car takes longer than the fleet in front, it starts a new fleet
            if (time > max_time) {
                fleets++;
                max_time = time;
            }
        }

        return fleets;
    }
};

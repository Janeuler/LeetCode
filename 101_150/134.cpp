//
// Created by janeuler on 2024/8/13.
//

# include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        int current_tank = 0;
        int total_tank = 0;
        int start_station = 0;
        for (int i = 0; i < gas.size(); i++) {
            current_tank += gas[i] - cost[i];
            total_tank += gas[i] - cost[i];

            if (current_tank < 0) {
                start_station = i + 1;
                current_tank = 0;
            }
        }

        return total_tank >= 0 ? start_station : -1;
    }
};

/*
Minimum Time to Repair Cars
You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
Return the minimum time taken to repair all the cars.
Note: All the mechanics can repair the cars simultaneously.
*/
class Solution {
    public:
        long repairCars(vector<int>& ranks, int cars) {
            int minRank = ranks[0], maxRank = ranks[0];

            // Find min and max rank dynamically
            for (int rank : ranks) {
                minRank = min(minRank, rank);
                maxRank = max(maxRank, rank);
            }

            // Frequency array to count mechanics with each rank
            vector<int> freq(maxRank + 1);
            for (int rank : ranks) {
                minRank = min(minRank, rank);
                freq[rank]++;
            }

            // Minimum possible time, Maximum possible time
            long long low = 1, high = 1LL * minRank * cars * cars;

            // Perform binary search to find the minimum time required
            while (low < high) {
                long long mid = (low + high) / 2;
                long long carsRepaired = 0;

                // Calculate the total number of cars that can be repaired in 'mid'
                // time
                for (int rank = 1; rank <= maxRank; rank++) {
                    carsRepaired +=
                        freq[rank] * (long long)sqrt(mid / (long long)rank);
                }

                // Adjust the search boundaries based on the number of cars repaired
                if (carsRepaired >= cars) {
                    high = mid;  // Try to find a smaller time
                } else {
                    low = mid + 1;  // Need more time
                }
            }

            return low;
        }
    };
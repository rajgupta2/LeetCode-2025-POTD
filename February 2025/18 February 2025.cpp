/*
Construct Smallest Number From DI String
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
A 0-indexed string num of length n + 1 is created using the following conditions:
num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.
*/
class Solution {
    public:
        string smallestNumber(string pattern) {
            string result = "";

            // Start building the sequence by calling the helper function
            buildSequence(0, 0, pattern, result);
            // Reverse the final result
            reverse(result.begin(), result.end());
            return result;
        }

        // Recursively build the sequence
        int buildSequence(int currentIndex, int currentCount, string pattern,
                          string& result) {
            if (currentIndex != pattern.size()) {
                if (pattern[currentIndex] == 'I')
                    // If 'I', increment the count and move to the next index
                    buildSequence(currentIndex + 1, currentIndex + 1, pattern,
                                  result);
                else
                    // If 'D', keep the count and move to the next index
                    currentCount = buildSequence(currentIndex + 1, currentCount,
                                                 pattern, result);
            }

            result += to_string(currentCount + 1);
            // Return the next count for the sequence
            return currentCount + 1;
        }
    };
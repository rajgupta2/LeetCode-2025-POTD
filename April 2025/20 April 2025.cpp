//Find Only Repetitive Element from 1 to n-1
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            sort(answers.begin(), answers.end());
            int res = 0, count = 0;

            for (int i = 0; i < answers.size(); ++i) {
                if (answers[i] == 0) {
                    res++;  // 🐇
                } else if (i == 0 || answers[i] != answers[i - 1] || count == 0) {
                    res += answers[i] + 1;
                    count = answers[i];
                } else {
                    count--;
                }
            }
            return res;
        }
    };
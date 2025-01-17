/*
Neighboring Bitwise XOR
A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.
Specifically, for each index i in the range [0, n - 1]:
If i = n - 1, then derived[i] = original[i] ⊕ original[0].
Otherwise, derived[i] = original[i] ⊕ original[i + 1].
Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.
Return true if such an array exists or false otherwise.
A binary array is an array containing only 0's and 1's
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
         vector<int> original = {0};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        // Store the validation results in checkForZero and checkForOne
        // respectively.
        bool checkForZero = (original[0] == original[original.size() - 1]);
        original = {1};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        bool checkForOne = (original[0] == original[original.size() - 1]);

        return checkForZero | checkForOne;
    }
};
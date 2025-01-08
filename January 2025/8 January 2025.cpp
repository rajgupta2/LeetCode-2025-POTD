/*
You are given a 0-indexed string array words.
Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix
and a suffix of str2, and false otherwise.
For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

Note: This code work is not done by me. As I have only a little knowledge of trie. I have taken this code from editorial section of leetcode to maintain the consistency.
but I will give my time to understand the topic trie so that next time I will solve it myself. Thank you
*/
class Node {
public:
    Node* links[26] = {};

    // Check if the character is present in the current node
    bool contains(char c) { return links[c - 'a'] != NULL; }

    // Insert a new node for the character
    void put(char c, Node* node) { links[c - 'a'] = node; }

    // Get the next node for the character
    Node* next(char c) { return links[c - 'a']; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    // Insert a word into the Trie
    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->next(c);
        }
    }

    // Check if the Trie contains a given prefix
    bool startsWith(string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->contains(c)) {
                return false;
            }
            node = node->next(c);
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        // Step 1: Iterate over each word
        for (int i = 0; i < n; i++) {
            Trie prefixTrie, suffixTrie;
            prefixTrie.insert(words[i]);
            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            for (int j = 0; j < i; j++) {
                if (words[j].size() > words[i].size()) continue;
                string prefixWord = words[j];
                string revPrefixWord = prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());

                if (prefixTrie.startsWith(prefixWord) &&
                    suffixTrie.startsWith(revPrefixWord)) {
                    count++;
                }
            }
        }
        return count;
    }
};
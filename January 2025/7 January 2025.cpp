/*
String Matching in an Array
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
A substring is a contiguous sequence of characters within a string
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        TrieNode* root = new TrieNode();

        for (const auto& word : words) {
            for (int startIndex = 0; startIndex < word.size(); startIndex++) {
                // Insert each suffix starting from index `startIndex`.
                insertWord(root, word.substr(startIndex));
            }
        }

        // Check each word to see if it exists as a substring in the Trie.
        for (auto word : words) {
            if (isSubstring(root, word)) {
                matchingWords.push_back(word);
            }
        }

        return matchingWords;
    }

private:
    class TrieNode {
    public:
        int frequency;
        unordered_map<char, TrieNode*> childNodes;
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            // If the character already exists as a child node, move to it.
            if (currentNode->childNodes.find(c) !=
                currentNode->childNodes.end()) {
                currentNode = currentNode->childNodes[c];
                // Increment the frequency of the node.
                currentNode->frequency++;
            } else {
                // If the character does not exist, create a new node.
                TrieNode* newNode = new TrieNode();
                // Initialize the frequency to 1.
                newNode->frequency = 1;
                currentNode->childNodes[c] = newNode;
                currentNode = newNode;  // Move to the new node.
            }
        }
    }

    bool isSubstring(TrieNode* root, string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            currentNode = currentNode->childNodes[c];
        }
        return currentNode->frequency > 1;
    }
};
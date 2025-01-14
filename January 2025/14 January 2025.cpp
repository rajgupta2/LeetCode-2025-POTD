/*
Find the Prefix Common Array of Two Arrays
You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      unordered_set<int> st;
      vector<int> ans;
      for(int i=0;i<A.size();i++){
        st.insert(A[i]);
        st.insert(B[i]);
        int num=2*(i+1);
        ans.push_back(num-st.size());
      }
      return ans;
    }
};
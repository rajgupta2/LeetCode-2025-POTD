/*
Product of the Last K Numbers
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.
Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
*/
class ProductOfNumbers {
    public:
        int size;
        vector<int> ans;
        ProductOfNumbers() {
            size=0;
        }

        void add(int num) {
            ans.push_back(num);
            size++;
        }

        int getProduct(int k) {
            int pro=1;
            for(int j=size-1;j>=0 && k>0;j--){
                pro*=ans[j];
                k--;
            }
            return pro;
        }
    };

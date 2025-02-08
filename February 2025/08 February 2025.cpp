/*
Design a Number Container System
Design a number container system that can do the following:
Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
*/
class NumberContainers {
    private:
        //number,vector<ind>
        unordered_map<int,set<int>> num;
        //ind,num
        unordered_map<int,int> ind;

    public:
    NumberContainers() {
    }

    void change(int index, int number) {
       if(ind.find(index)==ind.end()){
         ind[index]=number;
         num[number].insert(index);
       }else{
        //if there is a number in index alread
        //first remove from the num and that index
         int numberAlready=ind[index];
         num[numberAlready].erase(index);
         if(num[numberAlready].size()==0)
         num.erase(numberAlready);

         ind[index]=number;
         num[number].insert(index);
       }

    }

    int find(int number) {
        if(num.find(number)==num.end()) return -1;
        return *(num[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
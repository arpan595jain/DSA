class SmallestInfiniteSet {
public:
vector<int> arr;
    SmallestInfiniteSet() {
        int i;
        for(i=1;i<=1000;i++){
           arr.push_back(i);
        }
    }
    
    int popSmallest() {
        sort(arr.begin(),arr.end());
        int popped_value=arr[0];
        arr.erase(arr.begin()+0);
        return popped_value;
    }
    
    void addBack(int num) {
        if(count(arr.begin(),arr.end(),num)==0){
            arr.push_back(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

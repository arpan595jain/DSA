class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> counter;
        int c=0;
        for(int i=0;i<arr.size();i++){
            
            if(i==0){
               c=1;
            }
            else if(arr[i]==arr[i-1]){
                c++;
            }
            else if(arr[i]!=arr[i-1]){
                counter.push_back(c);
                c=1;

            }
          

        }
        counter.push_back(c);
        for(int j=0 ; j<counter.size();j++){
            for(int k=j+1;k<counter.size();k++){
                if(counter[j]==counter[k]){
                    return false;
                }
                else{
                    continue;
                }
            }
        }
        return true;

        
    }
};

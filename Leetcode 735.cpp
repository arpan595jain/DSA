class Solution {
public:
    void check(int num,vector<int>& st) {
       if(num>=0) st.push_back(num);
       else if(num < 0 && st.size() == 0) st.push_back(num);
        else if(num < 0 && st.back() < 0) st.push_back(num);
       else{
        int temp=st.back();
        st.pop_back();
        if(abs(temp)<abs(num)){
            check(num,st);
        }else if(abs(temp)>abs(num)){
            st.push_back(temp);
        }
       }
    }
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> st;
        for(int i=0;i<asteroids.size();i++){
           check(asteroids[i],st);
        }
    return st;
    }
};

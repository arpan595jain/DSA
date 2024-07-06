class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> r;
        queue<int> d;
        string R="Radiant";
        string D="Dire";
        for(int i=0;i<n;i++){
            (senate[i]=='R')? r.push(i):d.push(i);
        }
        while(!r.empty()&&!d.empty()){
            int temp1=r.front();
            int temp2=d.front();
            r.pop();
            d.pop();
            (temp1<temp2)?r.push(temp1+n):d.push(temp2+n);

        }
        return (r.size()>d.size())?R:D;
    }
};

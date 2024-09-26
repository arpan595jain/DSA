#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin>>x;
    long long r = 0;
    long long m = 1;
    bool f = true;
    while(x > 0){
        int d=x % 10;
        x /= 10; 
        if(d > 4){
            if(f && d==9){
            } 
            else{
                d = 9 - d;
            }
        }
        r += d * m;
        m *= 10;
        f = false;  
    }
    cout<<result<<endl;
    return 0;
}

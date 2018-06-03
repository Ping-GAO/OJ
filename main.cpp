#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct state{
    vector<int> Ring;
};
bool isPrime(int num);
int main() {
    int n;
    int cnt = 1;
    while(cin>>n){
        state original;
        original.Ring.push_back(1);
        queue<state> myQ;
        myQ.push(original);
        cout<<"Case "<<cnt<<":"<<endl;
        while(!myQ.empty()){
            state temp;
            temp = myQ.front();
            myQ.pop();
            if(temp.Ring.size()==n){

                for(unsigned i=0;i<temp.Ring.size();i++){

                    if(i==0){
                        cout<<temp.Ring[i];
                    }
                    else{
                        cout<<" "<<temp.Ring[i];
                    }
                }
                cout<<endl;
            }
            else if(temp.Ring.size()==n-1){
                int last = temp.Ring.back();
                int number[n+1];
                for(int i=1;i<=n;i++){
                    number[i] = i;
                }
                for(unsigned i=0;i<temp.Ring.size();i++){
                    number[temp.Ring[i]] = 0;
                }
                for(int i=1;i<=n;i++){
                    if(number[i]==0){
                        continue;
                    }
                    if(isPrime(number[i]+last) && isPrime(number[i]+1)){
                        state _new = temp;
                        _new.Ring.push_back(number[i]);
                        myQ.push(_new);
                    }
                }

            }
            else{
                int last = temp.Ring.back();
                int number[n+1];
                for(int i=1;i<=n;i++){
                    number[i] = i;
                }
                for(unsigned i=0;i<temp.Ring.size();i++){
                    number[temp.Ring[i]] = 0;
                }
                for(int i=1;i<=n;i++){
                    if(number[i]==0){
                        continue;
                    }
                    if(isPrime(number[i]+last)){
                        state _new = temp;
                        _new.Ring.push_back(number[i]);
                        myQ.push(_new);
                    }
                }
            }

        }
        cnt++;
        cout<<endl;

    }
    return 0;
}

bool isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}
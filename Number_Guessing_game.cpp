#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int n, guess, nguess=1;
    srand(time(0));
    n=rand()%100+1;
    do{
    cout<< "I have a number , guess what it is \n";
    cin >> guess;
    if(guess>n){
        cout << "Lower number please "<< endl;
    }
    else if(guess<n){
        cout << "Higher number please"<< endl;
    }
    else{
        cout << "You guessed it Right ! ,In "<< nguess << " attempts";
    }
    nguess++;
    }
    while (guess!= n);
    return 0;
    
}
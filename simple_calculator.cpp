#include<iostream>
using namespace std;
int main(){
    float a ,b;
    char c;
    cout<< "Enter number" <<endl;
    cin >>  a ;
    cout << "Enter operator (+,-,/,*): "; 
    cin >> c ;
    cout << "Enter second number" << endl;
    cin >> b ;
    switch(c){
        case '+':
        cout << a+b ;
        break;
        case '-':
        cout << a-b;
        break;
        case '*': 
        cout << a*b;
        break;
        case '/':
        if(b==0){
            cout << "invalid";
        }
        else {
            cout << a/b;
            break;
        }

    }
    
}

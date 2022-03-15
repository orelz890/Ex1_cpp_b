#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "mat.hpp"

// In order to run enter the following:
// g++ -o ans11.o my_main_test.cpp mat.cpp mat.hpp
// ./ans11
namespace ariel{
    void print_ans(){
        int n1, n2;
        char s1, s2;
        cout<<"Enter an odd number:"<<endl;
        cin>>n1;
        cout<<"Enter an odd number:"<<endl;
        cin>>n2;
        cout<<"Enter a sign:"<<endl;
        cin>>s1;
        cout<<"Enter a second sign:"<<endl;
        cin>>s2;
        cout<<"Your mat design:\n" + ariel::mat(n1,n2,s1,s2)<<endl; 
    }
}
int main(){

    ariel::print_ans();
    return 0;
}
#include <iostream>

int f(){ return 42; }
int f(int i){ return i; }

int main(){
    std::cout<<f()<<std::endl;
    std::cout<<f(7)<<std::endl;
}
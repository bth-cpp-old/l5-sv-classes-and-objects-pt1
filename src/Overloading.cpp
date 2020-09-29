#include <cassert>

int f(){ return 42; }
int f(int i){ return i; }

int main(){
    assert( f() == 42);
    assert( f(7) == 7);
}
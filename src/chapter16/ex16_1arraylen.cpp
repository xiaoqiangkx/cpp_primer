#include <iostream>

template <typename T, size_t N>
void show_array(T (&array)[N]) {
    for (int i=0; i<N; i++) {
        std::cout << array[i] << std::endl;        
    }
}

int main(int argc, char* argv[]) {
    int a[4] =  { 0 } ;
    int b[10] = { 1 } ;

    show_array(a);
    show_array(b);
    return 0;
}

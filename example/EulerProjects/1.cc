#include "1.hh"

int main(void) {
    const auto max_numbers = 1000;
    double sum = 0.0;
    for (auto i = 0; i < max_numbers; i+=3) {
        sum+= i;
    }
    for (auto i = 0; i < max_numbers; i+=5) {
        sum+= (i%3 !=0) * i;
    }
    std::cout<<"Sum: " <<sum<<std::endl;
    return 0;
};

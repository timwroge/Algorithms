#include "1.hh"
class Fibonacci {
    private:
        long _F_i;
        long _F_i_1;

    public:
        Fibonacci() : _F_i(1), _F_i_1(0)  {};
        long next() {
            auto new_fibonnacci = _F_i + _F_i_1;
            _F_i_1 = _F_i;
            _F_i = new_fibonnacci;
            return _F_i;
        };
        long current() {
            return _F_i;
        }
} ;

int main(void) {
    const auto max = 4000000;
    long sum = 0;
    auto  fibonacciGenerator = Fibonacci();
    auto currentFibonacci = 0.0;
    while( ( currentFibonacci = fibonacciGenerator.next() ) < max) {
        sum += ( not (static_cast<int>(currentFibonacci)%2) ) * currentFibonacci;
    }
    std::cout<<"Sum: " <<sum<<std::endl;
    return 0;
};

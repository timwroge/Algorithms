#include "3.hh"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>

class PrimeSieve{
    private:
        unsigned long _number;
        unsigned long _current_composite;
        unsigned long _current_prime;
        std::priority_queue<unsigned long,  std::vector<unsigned long>, std::less<unsigned long> > _factors;
        std::unordered_map<unsigned long, bool> _is_prime_table;
    public:
        PrimeSieve(unsigned long number) : _number(number),  _current_composite(number), _current_prime(2)  {
            // add 2 to the table
            _is_prime_table[2] = true;
            _is_prime_table[3] = true;
            _is_prime_table[5] = true;
        } ;
        bool isInPrimeTable(unsigned long number) {
            return _is_prime_table[number];
        };
        unsigned long isNotPrime(unsigned long number) {
            if(isInPrimeTable(number) ) {
                return 0;
            }
            unsigned long currentPrime = 5;
            // check if it is divisible by two or three..
            if(number==1 ) {
                return 0;
            }
            if(number%2==0 ) {
                return 2;
            }
            if(number%3 == 0) {
                return 3;
            }
            while(currentPrime  <  std::sqrt(number)) {
                if(number%currentPrime == 0) {
                    return currentPrime;
                }
                // we showed that it is not divisible by 6 so we can jump
                currentPrime+= 2;
            }
            _is_prime_table[currentPrime] = true;
            return 0;
        }
        unsigned long getNextPrime() {
            //so we know that even numbers are not prime, so if you are at a prime number
            //and its not two, then you have to update it by at least 2 to ensure it is
            //still odd
            //
            // The numbers can also be skipped if they are 6 away since 2 and 3 will occupy all the numbers
            // between
            if(_current_prime==2) {
                _current_prime = 3;
                return _current_prime;
            }
            if(_current_prime == 3) {
                _current_prime = 5;
                return _current_prime;
            }
            _is_prime_table[_current_prime] = true;
            do {
                _current_prime += 2;
            } while((isNotPrime (_current_prime) ));
            return _current_prime;
        };
        void getFactors() {
            _current_prime = 2;
            _current_composite = _number;
            while(isNotPrime(_current_composite)) {
                while( ( _current_composite%_current_prime ) == 0) {
                    _factors.push(_current_prime);
                    _current_composite/=_current_prime;
                }
                getNextPrime();
            }
            _current_prime = 2;
            _factors.push(_current_composite);
        }
        unsigned long getMaxPrimeFactor() {
            getFactors();
            auto result  = _factors.top();
            while(!_factors.empty()) {
                std::cout << _factors.top() << " ";
                _factors.pop();
            }
            std::cout << '\n';
            return result;
        }
} ;

int main(void) {
    const unsigned long starting_number =600851475143 ;
    auto sieve = PrimeSieve(starting_number);
    std::cout<<"Max Prime: " <<sieve.getMaxPrimeFactor()<<std::endl;
    return 0;
};

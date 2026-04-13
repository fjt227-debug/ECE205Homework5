#include <iostream>
using namespace std;

class PrimeNumber {
private:
    int prime;

    bool isPrime(int n) const {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int nextPrime(int n) const {
        //write your own function
        //hints: first increase n and pass through isprime function
        n++;
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int previousPrime(int n) const {
        //write your own function
        //hints: first decrease n and pass through isprime function
        n--;
        while (!isPrime(n))
        {
            n--;
        }
        return n;
    }

public:
    // Default constructor
    PrimeNumber() {
        prime = 1;
    }

    // Constructor with argument
    PrimeNumber(int p) {
        prime = p;
    }

    // Getter function
    int getPrime() const {
        return prime;
    }



    PrimeNumber operator++(int) {
        PrimeNumber temp;
        prime = nextPrime(prime);
        return temp;
    }

    PrimeNumber operator--(int) {
        PrimeNumber temp;
        prime = previousPrime(prime);
        return temp;
    }
};

int main() {
    PrimeNumber p1;          // default constructor
    PrimeNumber p2(13);      // constructor with value

    cout << "Default prime number: " << p1.getPrime() << endl;
    cout << "Initial p2: " << p2.getPrime() << endl;

    p2++;
    cout << "After postfix p2++: " << p2.getPrime() << endl;

    p2--;
    cout << "After postfix p2--: " << p2.getPrime() << endl;

    return 0;
}

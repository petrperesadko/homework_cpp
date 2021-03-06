
#include <iostream>

class Drob{
private:
    signed int n;
    int m;
    // n/m

public:
    Drob(){
        this->m = 1;
        this->n = 0;
    }
    Drob(int n) {
        this->m = 1;
        this->n = n;
    }
    Drob(int n, int m){
        this->m = m;
        this->n = n;
    }
    Drob(const Drob &another){
        this->n = another.n;
        this->m = another.m;
    }
    void Print(){
        std::cout << n << " " << m << std::endl;
    }

    bool operator == (const Drob &another){
        if(this->m == another.m && this->n == another.n) return true;
        else return false;
    }
    Drob &operator = (const Drob &another){
        this->n = another.n;
        this->m = another.m;
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
        return *this;
    }

    Drob &operator += (const Drob &another){
        int s = gcd(this->m, another.m);
        this->n = this->n * s / this->m + another.n * s / another.m;
        this->m = s;
        int l = lcm(this->n, this->m);
        this->n = this->n / l;
        this->m = this->m / l;
        if (this->m < 1)
        {
            this->m = -1 * this->m;
            this->n = -1 * this->n;
        }
        return *this;
    }
    Drob &operator -= (const Drob &another){
        int s = gcd(this->m, another.m);
        this->n = this->n * s / this->m - another.n * s / another.m;
        this->m = s;
        int l = lcm(this->n, this->m);
        this->n = this->n / l;
        this->m = this->m / l;
        if (this->m < 1)
        {
            this->m = -1 * this->m;
            this->n = -1 * this->n;
        }
        return *this;
    }
    Drob &operator *= (const Drob &another){
        this->n = this->n * another.n;
        this->m = this->m *another.m;
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
        return *this;
    }
    Drob &operator /= (const Drob &another) {
        this->n = this->n * another.m;
        this->m = this->m * another.n;
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
        return *this;
    }

    int gcd(int a, int b) {
        auto x = a;
        auto y = b;
        while (a && b)
            if (a > b) a %= b;
            else b %= a;

        return (x * y) / (a + b);
    }
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

};

int main() {
    Drob a(10, 5);
    Drob b(1, 2);
    b.Print();
    a.Print();
    a += b;
    a.Print();
    a *= b;
    a.Print();
    Drob c(a);
    c.Print();

    return 0;
}

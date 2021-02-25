
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
        this->n = another.m * this->n + another.n * this->m;
        this->m = this->m * another.n;
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
        return *this;
    }
    Drob &operator -= (const Drob &another){
        this->n = another.m * this->n - another.n * this->m;
        this->m = this->m * another.n;
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
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

//    Drob same(){
//        bool flag = true;
//        if(m == n){
//            n = 1;
//            m = 1;
//        }
//
//        else{
//            int temp = 0;
//            temp = std::min(m, n);
//            for(int i = 2; temp; i++){
//                if(n % i == 0 && m % i == 0){
//                    n = n / i;
//                    m = m / i;
//                }
//            }
//        }
//    }

    int gcd(int n, int m) {
        int x = 0;
        x = n;
        int y = 0;
        y = m;
        while (n && m) {
            if (n > m) n %= m;
            else m %= n;
        }
        return (x * y) / (n + m);
    }
    int lcm(int n, int m) {
        return (n * m) / gcd(n, m);
    }

};

int main() {
    Drob a(10, 5);
    Drob b(1, 2);
    a += b;
    b.Print();
    a.Print();

    return 0;
}

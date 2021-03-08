#include <iostream>
#include <cmath>
class Figure{
public:
    virtual double perimeter() const = 0;
    virtual double square() const = 0;
    virtual int angles_amount() const = 0;
};

class Circle : public Figure{
    friend class Rectangle;
public:
    Circle(double r): r(r){    };
    double perimeter () const override{
        return 2 * 3.14 * r;
    }
    double square () const override{
        return r * r * 3.14;
    }
    int angles_amount() const override{
        return 0;
    }
private:
    double r;
};

class Quad : public Figure {
public:
    Quad(double a): a(a){    };
    double perimeter() const override{
        return 4 * a;
    }
    double square() const override {
        return a * a;
    }
    int angles_amount() const override{
        return 4;
    }
private:
    double a;
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b): a(a), b(b){    };
    double perimeter()const override {
        return 2 * (a + b);
    }
    double square()const override {
        return a * b;
    }
    int angles_amount()const override{
        return 4;
    }
private:
    double a;
    double b;
};
class Triangle: public Figure{
public:
    Triangle(double a, double b, double angle){
        this->a = a;
        this->b = b;
        this->angle = angle;
    }
    double perimeter()const override {
        return a + b + sqrt(a * a + b * b - 2 * a * b *cos(angle));
    }
    double square()const override {
        return 0.5 * std::sin(angle) * a * b;
    }
    int angles_amount()const override{
        return 3;
    }

private:
    double a;
    double b;
    double angle;
};
class Elipse: public Figure{
public:
    Elipse(double a, double b): a(a), b(b){    };
    double perimeter()const override{
        return 4 * ((3.1415926 * a * b - (a - b)*(a - b)) / (a + b));
    }
    double square()const override {
        return 3.1415926 * a * b;
    }
    int angles_amount()const override{
        return 0;
    }
private:
    double a;
    double b;
};
int angles_amount(const Figure& figure){
    return figure.angles_amount();
}
double perimeter(const Figure& figure){
    return figure.perimeter();
}
double square(const Figure& figure){
    return figure.square();
}

int main(){

Quad q (5);
std::cout << square(q);


    return 0;
}
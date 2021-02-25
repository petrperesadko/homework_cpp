//
// Created by Петр on 19.02.2021.
//
// static
#include <iostream>
#include <cmath>
#include <vector>
class Figure{
public:
    virtual double perimeter() = 0;
    virtual double square() = 0;
    virtual int angles_amount() = 0;
};

class Circle : public Figure{
    friend class Rectangle;
public:
    Circle(double r){
        this->r = r;
    }
    double perimeter () override{
        return 2 * 3.14 * r;
    }
    double square (){
        return r * r * 3.14;
    }
    static double Pi(){
        return std::acos(-1);
    }
    int angles_amount() override{
        return 0;
    }
private:
    double r;
};

class Quad : public Figure {
public:
    Quad(double a){
        this->a = a;
    }
    double perimeter() override {
        return 4 * a;
    }
    double square() override {
        return a * a;
    }
    int angles_amount() override{
        return 4;
    }
private:
    double a;
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b){
        this->a = a;
        this->b = b;
    }
    double perimeter() override {
        return 2 * (a + b);
    }
    double square() override {
        return a * b;
    }
    int angles_amount() override{
        return 4;
    }
private:
    double a;
    double b;
};
class Ttiangle: public Figure{
public:
    Ttiangle(double a, double b, double angle){
        this->a = a;
        this->b = b;
        this->angle = angle;
    }
    double perimeter() override {
        return a + b + sqrt(a * a + b * b - 2 * a * b *cos(angle));
    }
    double square() override {
        return 0.5 * std::sin(angle) * a * b;
    }
    int angles_amount() override{
        return 3;
    }

private:
    double a;
    double b;
    double angle;
};
class Elipse: public Figure{
public:
    Elipse(double a, double b){
        this->b = b;
        this->a = a;
    }
    double perimeter() override{
        return 4 * ((3.1415926 * a * b - (a - b)*(a - b)) / (a + b));
    }
    double square() override {
        return 3.1415926 * a * b;
    }
    int angles_amount() override{
        return 0;
    }

private:
    double a;
    double b;
};


int main(){



    return 0;
}

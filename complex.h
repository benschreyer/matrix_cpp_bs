#ifndef _COMPLEX_H__
#define _COMPLEX_H__

#define MAGNITUDE_CUTOFF 0.000001

#include<string>
#include<math.h>
#include<iostream>
#include<array>
class Complex
{
    public:
        float a;
        float b;
        Complex(float a,  float b);
        Complex(std::array<float, 2>);

        std::string toString();

        Complex operator+(const Complex& x);
        Complex operator*(const Complex& x);

        Complex Conjugate();
        float Magnitude();

        //Complex pow(Complex x);





};

Complex::Complex(float a, float b)
{
    this->a = a;
    this->b = b;
}

Complex::Complex(std::array<float, 2> data)
{
    this->a = data[0];
    this->b = data[1];
}




std::string Complex::toString()
{
    return std::to_string(a) + " " + std::to_string(b) + "i";
}

Complex Complex::operator*(const Complex& x)
{
    Complex ret = Complex(x.a * this->a - (x.b * this->b), this->a * x.b + this->b * x.a);

    return ret;
}
Complex Complex::operator+(const Complex& x)
{
    return Complex(x.a + this->a, x.b + this->b);
}

Complex Complex::Conjugate()
{
    return Complex(this->a, -1.0 * this->b);
}

float Complex::Magnitude()
{
    return sqrt(((*this) * Complex(this->a, this->b * -1.0)).a);
}




#endif
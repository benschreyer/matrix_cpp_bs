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

        std::string toString() const;

        Complex operator+(const Complex& x) const;
        Complex operator*(const Complex& x) const;
        Complex operator/(const Complex& x) const;
        Complex operator*(const float x) const;
        Complex Conjugate() const;
        float MagnitudeSquared() const;
        float Magnitude() const;
        //static float MagnitudeOf(Complex& x);
        //static std::string toStringOf(const Complex& x);
        

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




std::string Complex::toString() const
{
    return std::to_string(a) + " " + std::to_string(b) + "i";
}



Complex Complex::operator*(const Complex& x) const
{
    Complex ret = Complex(x.a * this->a - (x.b * this->b), this->a * x.b + this->b * x.a);

    return ret;
}

Complex Complex::operator*(const float x) const
{
    Complex ret = Complex(x * this->a, this->b * x);

    return ret;
}

Complex Complex::operator/(const Complex& x) const
{
    Complex ret = (x.Conjugate() * (*this)) * (1/(x.MagnitudeSquared()) );

    return ret;
}

Complex Complex::operator+(const Complex& x) const
{
    return Complex(x.a + this->a, x.b + this->b);
}

Complex Complex::Conjugate() const
{
    return Complex(this->a, -1.0 * this->b);
}

float Complex::Magnitude() const
{
    return sqrt(this->MagnitudeSquared());
}

float Complex::MagnitudeSquared() const
{
    return ((*this) * this->Conjugate()).a;
}






#endif
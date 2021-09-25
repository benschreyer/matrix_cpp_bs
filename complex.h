#ifndef _COMPLEX_H__
#define _COMPLEX_H__



#include<string>
#include<math.h>
#include<iostream>
#include<array>
class Complex
{
    public:
        float a;
        float b;
        Complex();
        Complex(float a,  float b);
        Complex(std::array<float, 2>);
        //Complex();
        std::string toString() const;

        Complex operator-(const Complex& x) const;
        Complex operator+(const Complex& x) const;
        Complex operator*(const Complex& x) const;
        Complex operator/(const Complex& x) const;
        Complex operator*(const float x) const;
        Complex Conjugate() const;
        float MagnitudeSquared() const;
        float Magnitude() const;

        

        float _magnitudeOf(const Complex x);
        std::string _toStringOf(const Complex x) ;


        //static Complex _defaultValue = {0.0,0.0};
        //static std::string (*toStringFunction)(const Complex x) = &_toStringOf;
        //static float (*magnitudeFunction)(const Complex x) = &_magnitudeOf;

        //static float MagnitudeOf(Complex& x);
        //static std::string toStringOf(const Complex& x);
        

        //Complex pow(Complex x);





};

Complex::Complex()
{
    this->a = 0.0;
    this->b = 0.0;
}

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

Complex Complex::operator-(const Complex& x) const
{
    return Complex(-1.0 * x.a + this->a, -1.0 * x.b + this->b);
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

float Complex::_magnitudeOf(const Complex x)
{
    return x.Magnitude();
}

std::string Complex::_toStringOf(const Complex x) 
{
    return x.toString();
}




#endif
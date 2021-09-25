#include"matrix.h"
#include"complex.h"
#include<iostream>
#include<math.h>




int main(void)
{
   /* std::cout << "ABC\n";
    Matrix<2, 2, float> m = Matrix<2, 2, float>(&std::to_string, &fabs,{1.9, -0.9, 1.1, 32.0},0.0);
    Matrix<2, 2, float> mp = Matrix<2, 2, float>(&std::to_string, &fabs,{0.9, -1.9, -1.1, 33.0},0.0);
    Matrix<2, 1, float> m1 = Matrix<2, 1, float>(&std::to_string, &fabs,{1.9, -0.9},0.0);
    Matrix<2, 1, float> m2 = Matrix<2, 1, float>(&std::to_string, &fabs,{-1.9, -1.9},0.0);

    std::cout << m.getEntry(1,0) << "\n\n";
    std::cout << m.toString() << "\n";
    std::cout << m1.toString() << "\n";
    std::cout << (m * m1).toString();
    std::cout << (m1 +  m1).toString() << "\n";
    std::cout << (m + m).toString() << "\n";
    std::cout << (m + mp).toString() << "\n";
    std::cout << (m1 + m2).toString() << "\n";
    std::cout << (m1 * 3).toString() << "\n\n\n";

    Matrix<3, 4, float> RRedMe = Matrix<3, 4, float>(&std::to_string, &fabs,{0.9, -1.9, 2.0, 1.0, -1.1, 33.0, 12.0, 9.2, 1.0 ,34.0, 3.0, 2.2},0.0);

    std::cout << RRedMe.toString() << "\n";
    std::cout << RRedMe.RRef().toString() << "\n";*/

    Complex z = {-3, 4};
    Complex b = {2, 0};
    //std::cout << z.toString() << "   " << z.Magnitude() << "    "<< (z + z * z.Conjugate()).toString() << "   "<<  (z/b).toString() << "\n";
    //const std::array<Complex&,12> ar = {Complex(3.0, 4.0), Complex(1.1, -2.2), Complex(7.1,0.0), Complex(99.0,-2.0),Complex(3.0, 24.0), Complex(1.321, -22.2), Complex(71.1,0.0), Complex(99.0,-232.0),Complex(3.0, 34.0), Complex(13.1, -2.2), Complex(7.1,202.0), Complex(199.0,-2.0)};
    
    Complex mat[12] = 
    {
    {3.0, 4.0}, {1.1, -2.2}, {7.1,0.0}, {99.0,-2.0},
    {3.0, 24.0}, {1.321, -22.2}, {71.1,0.0}, {99.0,-232.0},
    {3.0, 34.0}, {13.1, -2.2}, {7.1,202.0}, {199.0,-2.0}
    };
    //std::cout << mat[3].toString();
    Matrix<3, 4, Complex> testComplexMatrix = Matrix<3, 4, Complex>( &mat[0]);

    std::cout << testComplexMatrix.toString() << "\n\n\n";
    std::cout << testComplexMatrix.RRef().toString() << "\n\n\n";
    std::cout << ( testComplexMatrix * Complex(2.0,0.0) + testComplexMatrix).RRef().toString() << "\n\n\n";

    return 0;
}
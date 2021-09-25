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
    
    Complex mat[90] = 
    {
    {443.0, 54.0}, {14.1, -52.2}, {37.1,0.0}, {939.0,-2.0},
    {3.0, 4424.0}, {1.321, -22.2}, {71.1,0.0}, {929.0,-23332.0},
    {43.0,6344.0}, {13.1, -2.2}, 
    {3.0, 4.0}, {1.71, -2.2}, {722.1,0.0}, {9913.0,-2.0},
    {3.40, 24.0}, {188.321, -223.2}, {7131.1,0.0}, {939.0,-232.0},
    {3.0, 34.0}, {13.1, -2.2}, 
    {3.0, 4.50}, {81.1, -2.2}, {73.1,0.0}, {919.10,-2.0},
    {33.0, 24.0}, {18.321, -22.2}, {371.1,0.0}, {19559.0,-232.0},
    {3.0, 34.0}, {13.1, -2.2}, 
    {3.0, 41.0}, {1.71, -2.2}, {71.1,0.3203}, {599.0,-2.0},
    {3.0, 24.40}, {1.321, -22.2}, {71.1,0.0}, {995.0,-232.0},
    {3.0, 34.0}, {13.1, -2.2}, 
    {31.0, 4.0}, {1.1, -2.2}, {337.1,0.0}, {599.0,-2.0},
    {3.0, 234.0}, {1.321, -22.2}, {371.13,0.0}, {919.0,-232.0},
    {31.0, 34.0}, {123.1, -2.2}, 
    {3.0, 43.40}, {1.1, -2.2}, {1733.1,0.0}, {995.0,-2.0},
    {3.0, 24.0}, {1.3321, -22.2}, {73331.1,0.0}, {919.0,-2332.0},
    {3.0, 334.0}, {13.1, -2.2}, 
    {3.0, 4.40}, {1.1, -2.2}, {517.1,0.0}, {399.0,-233.0},
    {3.0, 24.0}, {12.321, -22.2}, {7113.1,0.0}, {9159.0,-232.0},
    {23.0, 34.40}, {13.1, -2.2}, 
    {3.0, 4.0}, {1.1, -2.2}, {157.1,0.0}, {9911.0,-52.0},
    {3.0, 24.0}, {1.321, -22.2}, {73331.1,0.0}, {99.0,-2132.0},
    {3.0, 34.0}, {133.1, -2.2}, 
    {3.0, 4.0}, {1.1, -2.2}, {7.1,02.0}, {919.0,-2.0},
    {3.30, 24.0}, {122.321, -22.2}, {71.1,0.0}, {9429.0,-232222.0},
    {33.0, 34.0}, {1332.1, -322.2}, 
    };
    //std::cout << mat[3].toString();
    Matrix<9, 10, Complex> testComplexMatrix = Matrix<9, 10, Complex>( &mat[0]);

    std::cout << testComplexMatrix.toString() << "\n\n\n";
    std::cout << testComplexMatrix.RRef().toString() << "\n\n\n";
    std::cout << ( testComplexMatrix * Complex(2.0,0.0) + testComplexMatrix).RRef().toString() << "\n\n\n";

    return 0;
}
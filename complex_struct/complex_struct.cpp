// complex_struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct complex {
    double Re;
    double Im;
};

void set(complex& z, double a = 0, double b = 0) {
    z.Re = a;
    z.Im = b;
}

double getRe(const complex& z) {
    return z.Re;
}

double getIm(const complex& z) {
    return z.Im;
}

void print_cplx(const complex& z) {
    std::cout << getRe(z) << "+" << getIm(z) << "i";
}

complex sum(const complex& z1, const complex& z2) {
    complex res;
    set(res, z1.Re + z2.Re, z1.Im + z2.Im);
    return res;
}

complex add(complex& z1, const complex& z2)
{
    z1.Re += z2.Re;
    z1.Im += z2.Im;
    return z1;
}

int main()
{
    complex z1, z2;
    set(z1, 1, 2);
    set(z2, 3, 4);
    std::cout << "z1 = ";
    print_cplx(z1);
    std::cout << "\nz2 = ";
    print_cplx(z2);
    std::cout << "\nz1 + z2 = ";
    print_cplx(sum(z1, z2));
    std::cout << "\nz1 += z2  ";
    print_cplx(add(z1, z2));
    std::cout << "\nz1 = ";
    print_cplx(z1);
    std::cout << "\n";
}

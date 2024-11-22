// complex_struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

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

complex& add(complex& z1, const complex& z2)
{
    z1.Re += z2.Re;
    z1.Im += z2.Im;
    return z1;
}

double cplx_mod2(const complex& z1){
    return z1.Re * z1.Re + z1.Im * z1.Im;
}

int comp_cplx_mod(const complex& z1, const complex& z2) {
    return cplx_mod2(z1) > cplx_mod2(z2) ? 1 : -1;
}

void sort(complex* arr, size_t n, std::function<int(const complex&, const complex&)> comp) {
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n - i - 1; ++j)
            if (comp(arr[j], arr[j+1]) > 0) {
                complex temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
    std::cout << "\n(z1 += z2) += z2  ";
    print_cplx(add(add(z1, z2), z2));
    std::cout << "\nz1 = ";
    print_cplx(z1);
    std::cout << "\n";

    complex arr[3] = {};
    set(arr[0], 1, 0);
    set(arr[1], 3, 0);
    set(arr[2], 2, 0);

    sort(arr, 3, comp_cplx_mod);
    for (int i = 0; i < 3; ++i) {
        print_cplx(arr[i]);
        std::cout << "\n";
    }
}

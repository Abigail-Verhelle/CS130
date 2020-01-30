#include <iostream>
using namespace std;


struct Polynomial
{
    int coef[10]; // coefficients
    int degree;   // highest degree
};

Polynomial operator+(Polynomial a, Polynomial b)
{
    
    Polynomial p;
    
    
    
}

std:: ostream& operator<< (std::ostream& output, Polynomial p)
{
    output << p.coef[p.degree] << "x^" << d << "+";
    for (int x = p.degree - 1; x >= 0; x--)
    {
        if (p.coef[x] < 0)
        {
            output << " - " << p.coef[x] * -1 << "x^" << d ;
        }
        
        else
        {
        output << " + " << p.coef[x] << "x^" << d ;
        }
    }
}


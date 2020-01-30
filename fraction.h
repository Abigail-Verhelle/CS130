#include <iostream>
using namespace std;

struct Fraction {
    int num;
    int den;
};

// A function to calculate the greatest common divisor will be usefu l
int gcd(int a, int b)
{
    if( b == 0 )
        return a;
    return gcd(b,a%b);
}

// All fraction values are reduced
// For example, we have 3/4 and never 9/12
// It would be good to create a function to do that
void reduce(Fraction &f)
{
    //declare holder for finished product
    Fraction reduce = f;
    //get divisor
   int divisor = gcd(reduce.num,reduce.den);
//if divisor = 0 then concatinate
    if ( reduce.num%divisor == 0 && reduce.den%divisor == 0 )
    {
        reduce.num = reduce.num/divisor;
        reduce.den = reduce.den/divisor;
    }
    
}

istream& operator>>(istream& in, Fraction &f)
{
    // Implement fraction input here
    in >> f.num >> f.den;
    return in;
    
}

ostream& operator<<(ostream& out, Fraction f)
{
    // Implement fraction output here
    out << f.num << '/' << f.den;
    return out; 
}

Fraction operator+(Fraction a, Fraction b)
{
    Fraction total;
//    Fraction l;
    // Implement fraction addition here
    // add both denominators and then use the common denom to add the rest
    total.num = a.num + b.num;
    total.den = a.den + b.den;
    
//    l = reduce(total);
    return total;
    
}

Fraction operator-(Fraction a, Fraction b)
{
    Fraction difference;
//    Fraction d;
    // Implement fraction subtraction (a-b) here
    // kind of the same way as adding
    
    difference.num = a.den + b.den;
    difference.den = a.den + b.den;
    
//    differnce = reduce(differnce);
    
    return differnce;
    
}

Fraction operator*(Fraction a, Fraction b)
{
    Fraction mult;
//    fraction m;
    // Implement fraction multiplication here
    //mult straight across
    mult.num = a.num * b.num;
    mult.den = a.den * b.den;
    
//    m = reduce(mult.num,mult.den);
    
    return mult;
}

Fraction operator/(Fraction a, Fraction b)
{
    Fraction division;
//    Fraction d;
    // Implement fraction division (a/b) here
    division.num = b.den;
    division.den = b.num;
    
//    d = mult(division,a)
    
    return division;
    
    
}



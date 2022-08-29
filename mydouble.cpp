//doubles
#include <map>
#include <cmath>
#include <iostream>
#include "mydouble.h"
#include <fstream>
using namespace std;

double Mydouble::count = 0;
std::map <double, long int> Mydouble::doubles;

const std::map<double, long int>& Mydouble::getmap()
{
    return Mydouble::doubles;
}

void Mydouble::map_insert(double x)
{
    const double r = 1e-2; // resolution
    double q = round(x/r)*r;
    if (doubles.find(q) == doubles.end()) {
        doubles.insert(std::pair<double, long int>(q, 0));
    }
    doubles[q]++;
    count++;
}

Mydouble::Mydouble(double x) : x(x)
{
    map_insert(x);
}

Mydouble::Mydouble(const Mydouble &&other) : x(other.x)
{ }

Mydouble::Mydouble(const Mydouble &other) : x(other.x)
{
    map_insert(x);
}

int Mydouble::getcount()
{
    return count;
}

Mydouble operator- (const Mydouble &d1, const Mydouble &d2)
{
    Mydouble sub(d1.x - d2.x);
    return sub;
}

ostream& operator<< (ostream& out, const Mydouble &d1)
{
    out << d1.x;
    return out;
}


Mydouble operator* (const Mydouble &d1, const Mydouble &d2)
{
    Mydouble mult(d1.x * d2.x);
    return mult;
}

Mydouble operator/ (const Mydouble &d1, const Mydouble &d2)
{
    const Mydouble div(d1.x / d2.x);
    return div;
}

bool operator> (const Mydouble &d1, const Mydouble &d2)
{
    return (d1.x>d2.x);
}

double Mydouble::getdouble() const
{
    return x;
}

bool operator< (const Mydouble &d1, const Mydouble &d2)
{
    return d1.getdouble() < d2.getdouble();
}

Mydouble floor(const Mydouble &d1)
{
    Mydouble d2(floor(d1.x));
    return d2;
}

Mydouble abs(const Mydouble &d1)
{
    Mydouble d2(abs(d1.x));
    return d2;
}

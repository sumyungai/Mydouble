#ifndef MYDOUBLE_H
#define MYDOUBLE_H
#include <map>
#include <cmath>
#include <iostream>
#include <float.h>
class Mydouble
{
public:  
        Mydouble(double x = 0.0);
        Mydouble(const Mydouble &other); 
        Mydouble(const Mydouble &&other);

        static const std::map<double, long int>& getmap();
        static int getcount();
        double getdouble() const;
        std::string convert();      
private:
        static std::map <double,long int> doubles;
        static double count;
        double x;

        void map_insert(double num);

public:

    friend Mydouble operator- (const Mydouble &d1, const Mydouble &d2);
    friend std::ostream& operator<< (std::ostream &out, const Mydouble &d1);
    friend bool operator==(const Mydouble &d1, const Mydouble &d2);
    friend Mydouble operator* (const Mydouble &d1, const Mydouble &d2);
    friend Mydouble operator/ (const Mydouble &d1, const Mydouble &d2);
    friend bool operator> (const Mydouble &d1, const Mydouble &d2);
    friend bool operator>= (const Mydouble &d1, const Mydouble &d2);
    friend bool operator< (const Mydouble &d1, const Mydouble &d2);
    friend Mydouble floor(const Mydouble &d1);
    friend Mydouble abs(const Mydouble &d1);

    template <typename T>
    friend Mydouble operator- (const T &d1, const Mydouble &d2)
    {
        Mydouble temp = d1 - d2.x;
        return temp;
    }
    template <typename T>
    friend Mydouble operator+ (const T &d1, const Mydouble &d2)
    {
        Mydouble temp = d1 + d2.x;
        return temp;
    }

    template <typename T>
    friend Mydouble operator/ (const T &d1, const Mydouble &d2)
    {
        Mydouble temp = d1 / d2.x;
        return temp;
    }

    template <typename T>
    friend Mydouble operator* (const T &d1, const Mydouble &d2)
    {
        Mydouble temp = d1*d2.x;
        return temp;
    }

    template <typename T>
    Mydouble operator- (const T &d2) const
    {
        Mydouble temp = this->x - d2;
        return temp;
    }

    template <typename T>
    Mydouble operator+ (const T &d2) const
    {
        Mydouble temp = this->x+d2;
        return temp;
    }
    template <typename T>
    Mydouble operator/ (const T &d2) const
    {
        Mydouble temp = this->x / d2;
        return temp;
    }

    template <typename T>
    Mydouble operator* (const T &d2) const
    {
        Mydouble temp = this->x * d2;
        return temp;
    }
    template <typename T>
    bool operator==(const T &d2) const
    {
        bool temp = this->x == d2;
        return temp;
    }
    friend bool operator==(const Mydouble &d1, const Mydouble &d2)
    {
        return d1.x==d2.x;
    }
    template <typename T>
    friend bool operator==(const T &d1, const Mydouble &d2)
    {
        bool temp = d1 == d2.x;
        return temp;
    }

    template <typename T>
    Mydouble& operator=(T &d2) 
    {
        this->x = d2;
        return *this;
    }

    Mydouble& operator=(const Mydouble &d)
    {
        if (&d == this) { return *this; }
        this->x = d.x;
        return *this;
    }

    template <typename T>
    friend bool operator> (const T &d1, const Mydouble &d2)
    {
        bool temp = d1> d2.x; 
        return temp;
    }

    template <typename T>
    bool operator> (const T &d2) const
    {
        bool temp = this->x > d2;
        return temp;
    }

    template <typename T>
    friend bool operator>= (const T &d1, const Mydouble &d2)
    {   
        bool temp = d1>= d2.x;
        return temp;
    }

    template <typename T>
    bool operator>= (const T &d2) const
    {
        bool temp = this->x>=d2;
        return temp;
    }
    
    bool operator>= (const Mydouble &d2) const
    {
        bool temp = this->x>=d2.x;
        return temp;
    } 

    template <typename T>
    friend T& operator-= (T &d1,const Mydouble &d2)
    {
        d1= d1-d2.x;
        return d1;
    }
    template <typename T>
    Mydouble& operator-= (const T &d2) 
    {
        this->x = this->x-d2;
        return *this;
    }

    Mydouble& operator-= (const Mydouble &d2) 
    {
        this->x -= d2.x;
        return *this;
    }

    template <typename T>
    friend T& operator+= (T &d1,const Mydouble &d2)
    {
        d1= d1+d2.x;
        return d1;
    }

    template <typename T>
    Mydouble& operator+= (const T &d2) 
    {
        this->x = this->x+d2;
        return *this;
    }
     
    Mydouble& operator+= (const Mydouble &d2) 
    {
        this->x += d2.x;
        return *this;
    }

template <typename T>
    friend T& operator*= (T &d1,const Mydouble &d2)
    {
        d1= d1*d2.x;
        return d1;
    }

    template <typename T>
    Mydouble& operator*= (const T &d2) 
    {
        this->x = this->x*d2;
        return *this;
    }
     
    Mydouble& operator*= (const Mydouble &d2) 
    {
        this->x *= d2.x;
        return *this;
    }



    template <typename T>
    friend bool operator< (const T &d1, const Mydouble &d2)
    {
        bool temp = d1<d2.x;
        return temp;
    }
    template <typename T>
    bool operator< (const T &d2) const
    {
        bool temp = this->x<d2;
        return temp;
    }
    
    template <typename T>
    bool operator!=(const T &d2) const
    {
        bool temp = !(this->x == d2);
        return temp;
    }

    template <typename T>
    friend bool operator!=(const T &d1, const Mydouble &d2)
    {
        bool temp = !(d1 == d2.x);
        return temp;
    }

    operator int() const
    {
        return (int)x;
    }

    operator size_t() const
    {
        return (size_t)x;
    }

    operator double() const
    {
        return x;
    }
    operator float() const
    {
        return (float)x;
    }
    operator unsigned() const
    {
        return (unsigned)x;
    }

    void set_max() { x = DBL_MAX; }
    void set_min() { x = DBL_MIN; }
    void set_epsilon() { x = DBL_EPSILON; }
    void set_next()
    {
        if (x < DBL_MAX) {
            x = nextafter(x, DBL_MAX);
        }
    }
    void set_prev()
    {
        if (x > DBL_MIN) {
            x = nextafter(x, DBL_MIN);
        }
    }
};

 
#endif


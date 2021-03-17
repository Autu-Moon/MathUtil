#pragma once
#include <iostream>
#include <valarray>
using namespace std;

template<typename T> class Twin
{
public:
    std::valarray<T> thearray;
    Twin() :thearray(2) {};
    Twin(const Twin& right) :thearray(right.thearray) {};
    Twin(T a, T b) :thearray(2)
    {
        thearray[0] = a;
        thearray[1] = b;
    }

    T operator[](const size_t index) const
    {
        return thearray[index];
    }
    T& operator[](const size_t index)
    {
        return thearray[index];
    }
    Twin& operator= (const Twin &right)
    {
        this->thearray[0] = right[0];
        this->thearray[1] = right[1];
        return *this;
    }
    T squre(){
        return thearray[0] * thearray[0] +
               thearray[1] * thearray[1];
    }
    T norm() {
        return sqrt(thearray[0] * thearray[0] +
                    thearray[1] * thearray[1] );
    }
    template <typename T1>
    friend ostream& operator<<(ostream &out,const Twin<T1>& t);
};
template <typename T>
inline ostream& operator<<(ostream &out, const Twin<T>& t)
{
    out << "( " << t[0] << " , " << t[1] << " )";
    return out;
}

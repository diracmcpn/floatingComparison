/*
 *Due to the floating-point format, the comparison of two float numbers often raises accuracy problems.
 *See "http://en.wikipedia.org/wiki/Floating_point" in wikipedia.
 *To resolve it, we can define inline functions that make a comparison with some accuracy.
*/

#include <iostream>
#define PREC 0.000001 //10^-6 (the wanted accuracy). Example : a ~ b (+ or - PREC);

// a == b
inline bool equals(double a, double b);
inline bool equals(double a, double b)
{
    return (a<b)?(b-a<PREC):(a-b<PREC);
};

// a > b
inline bool sups(double a, double b);
inline bool sups(double a, double b)
{
    return ((!equals(a,b))&&(a-b>PREC));
};

// a < b
inline bool infs(double a, double b);
inline bool infs(double a, double b)
{
    return ((!equals(a,b))&&(a-b<PREC));
};

// a >= b . Use sups(a,b)||equals(a,b)

// a <= b . Use infs(a,b)||equals(a,b)


using namespace std;

int main()
{
    double pointa = 0.1;
    double pointb = 0.1*6;
    double pointc = 0.6;

    cout<<"(without correction): b equals c ? "<<(pointb==pointc)<<endl;
    cout<<"(with correction): b equals c ? "<<equals(pointb, pointc)<<endl;

    return 0;
}

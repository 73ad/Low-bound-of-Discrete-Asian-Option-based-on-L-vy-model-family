//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  AverageLEVY.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef AverageLEVY_h
#define AverageLEVY_h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "AverageBase.h"

#include <complex>

class Input;
class UAModelBase;
class PseudoFactory;

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class AverageLEVY: public AverageBase
{
    public:
        AverageLEVY(Input& inp, PseudoFactory& fac);
        ~AverageLEVY(){};
        std::complex<double> Process(std::complex<double> u,
                                    std::complex<double> v, int k, int n) const;
        std::complex<double> Sum(std::complex<double> u, std::complex<double> v,
                                                     int h, int k, int n) const;
        std::complex<double> Eta(std::complex<double> u,std::complex<double> v,
                                              int j, int k, int n, int N) const;
        std::complex<double> Levy(std::complex<double> u)  const;
    private:
        double s_0_;
        double r_;
        double q_;
        double delta_0_;
        double T_;
        int N_;
    
        UAModelBase * uam_;
    
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#endif
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    OptionFix.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "OptionFix.h"

#include "Input.h"

#include "PseudoFactory.h"

#include "AverageBase.h"

#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    interface
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

OptionFix::OptionFix(Input & inp,PseudoFactory & fac)
:   T_(inp.GetT())
,   r_(inp.Getr())
,   N_(inp.GetN())
,   K_(inp.GetK())
{
    ave_ = fac.CreateAVE();
}
std::complex<double> OptionFix::option(double u, double delta) const
{
    std::complex<double> u1(0.,-0.5);
    std::complex<double> v1(u,-delta);
    std::complex<double> u2(0.,0.);
    
    std::complex<double> sumA(0.,0.);
    std::complex<double> B;
    
    std::complex<double> i(0,1.0);
    
    for (int k = 0; k <= N_; ++k)
    {
        sumA += ave_->Process(u1,v1,k,k);
    }
    B = ave_->Process(u2,v1,N_,N_);
    
    std::complex<double> PHI = exp(-r_ * T_)/(i * u + delta) * (sumA/ (double)(N_ + 1) - K_ * B);
    //std::cout<<"option " <<std::endl;
    return PHI;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

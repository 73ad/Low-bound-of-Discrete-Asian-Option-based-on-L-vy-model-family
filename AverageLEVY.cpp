//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  AverageLEVY.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "AverageLEVY.h"

#include "Input.h"

#include "PseudoFactory.h"

#include "UAModelBase.h"

#include <cmath>
#include <iostream>

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
AverageLEVY::AverageLEVY(Input& inp, PseudoFactory& fac)
:   s_0_(inp.GetS0())
,   r_(inp.Getr())
,   q_(inp.Getq())
,   T_(inp.GetT())
,   N_(inp.GetN())
{
    delta_0_ = T_ / (double) N_;
    uam_ = fac.CreateUAM();
}

std::complex<double> AverageLEVY::Process(std::complex<double> u,
                                     std::complex<double> v, int k, int n) const
{
    int h = 0;
    double X = log(s_0_);
    std::complex<double> i(0,1);
    std::complex<double> fi = exp( i * ( 2.0 * u + v) * X + Sum(u, v, h, k, n));
    //std::cout<<"ave"<<std::endl;
    return fi;
}

std::complex<double> AverageLEVY::Sum(std::complex<double> u,
                              std::complex<double> v, int h, int k, int n) const
{
    std::complex<double> sum(0,0);
    for (int j = h+1; j <= N_; ++j)
    {
        sum += Levy(Eta(u, v, j, k, n, N_));
    }
    return sum;
}

std::complex<double> AverageLEVY::Levy(std::complex<double> u) const
{
    std::complex<double> i(0,1);
    
    return uam_->Model(u, delta_0_) + i* u*  delta_0_* (r_- q_- uam_->Model(-i, 1));
}

std::complex<double> AverageLEVY::Eta(std::complex<double> u,
                       std::complex<double> v, int j, int k, int n, int N_) const
{
    int max = (n > k)? n:k;
    int min = (n > k)? k:n;
    
    std::complex<double> f = v * (1 - (double)j/(double)(N_ + 1));
    std::complex<double> c;
    
    if (j > max && j < N_){ c = f;}
    else if (j > min){ c = u + f;}
    else if (j > 0){ c = 2.0 * u + f;}
    return c;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

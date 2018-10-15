//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  UAModelDEJD.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "UAModelDEJD.h"
#include "Input.h"

#include <cmath>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
UAModelDEJD::UAModelDEJD(Input & inp)
	: sigma_(inp.Getdejd_sigma())
	, T_(inp.GetT())
	, N_(inp.GetN())
	, l_(inp.Getdejd_l())
	, p_(inp.Getdejd_p())
	, n1_(inp.Getdejd_n1())
	, n2_(inp.Getdejd_n2())

{
	delta_0_ = T_ / (double)N_;
}

std::complex<double> UAModelDEJD::Model(std::complex<double> u, double v) const
{
	//std::cout<<"gau"<<std::endl;
	std::complex<double>i(0.0, 1);
	return l_*delta_0_*(p_*n1_/(n1_-i*u)+(1.0-p_)*n2_/(n2_+i*u)-1.0)-0.5*sigma_*sigma_*u*u*delta_0_;
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

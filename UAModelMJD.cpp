//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  UAModelCGMY.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "UAModelMJD.h"
#include "Input.h"

#include <cmath>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
UAModelMJD::UAModelMJD(Input & inp)
	: sigma_(inp.Getmjd_sigma())
	, T_(inp.GetT())
	, N_(inp.GetN())
	, mux_(inp.Getmjd_mux())
	, sigx_(inp.Getmjd_sigx())
	, l_(inp.Getmjd_l())
{
	delta_0_ = T_ / (double)N_;
}

std::complex<double> UAModelMJD::Model(std::complex<double> u, double v) const
{
	//std::cout<<"gau"<<std::endl;
	std::complex<double>i(0.0, 1);
	return l_*delta_0_*(exp(i*u*mux_-0.5*u*u*sigx_*sigx_)-1.0)-0.5*sigma_*sigma_*u*u*delta_0_;
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

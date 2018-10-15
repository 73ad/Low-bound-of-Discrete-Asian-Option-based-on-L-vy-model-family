//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  UAModelCGMY.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "UAModelCGMY.h"
#include "Input.h"

#include <cmath>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
UAModelCGMY::UAModelCGMY(Input & inp)
	: T_(inp.GetT())
	, N_(inp.GetN())
	, c_(inp.Getcgmy_c())
	, g_(inp.Getcgmy_g())
	, m_(inp.Getcgmy_m())
	, y_(inp.Getcgmy_y())
{
	delta_0_ = T_ / (double)N_;
}

std::complex<double> UAModelCGMY::Model(std::complex<double> u, double v) const
{
	//std::cout<<"gau"<<std::endl;
	std::complex<double>i(0.0, 1);
	return c_ * v * tgamma(-y_) * std::pow(m_ - i * u, y_) - std::pow(m_, y_) + std::pow(g_+i*u,y_) - std::pow(g_,y_);
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  UAModelNIG.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "UAModelNIG.h"
#include "Input.h"

#include <cmath>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
UAModelNIG::UAModelNIG(Input & inp)
	: T_(inp.GetT())
	, N_(inp.GetN())
	, delta_(inp.Getnig_delta())
	, a_(inp.Getnig_a())
    , b_(inp.Getnig_b())
{
	delta_0_ = T_ / (double)N_;
}

std::complex<double> UAModelNIG::Model(std::complex<double> u, double v) const
{
	//std::cout<<"gau"<<std::endl;
	std::complex<double>i(0.0, 1);
	return -delta_ * delta_0_ * (sqrt(a_ * a_- (b_ + u * i) * (b_ + u * i)) - sqrt(a_* a_- b_* b_));
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

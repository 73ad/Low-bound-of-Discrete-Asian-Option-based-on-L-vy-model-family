//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  UAModelMeixner.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "UAModelMeixner.h"
#include "Input.h"

#include <cmath>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    constructor
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
UAModelMeixner::UAModelMeixner(Input & inp)
	: T_(inp.GetT())
	, N_(inp.GetN())
	, delta_(inp.Getmei_delta())
	, a_(inp.Getmei_a())
	, b_(inp.Getmei_b())

{
	delta_0_ = T_ / (double)N_;
}

std::complex<double> UAModelMeixner::Model(std::complex<double> u, double v) const
{
	//std::cout<<"gau"<<std::endl;
	std::complex<double>i(0.0, 1);
	return 2.0 * delta_ * v *log(cos(b_/ 2.0)/(0.5 * cosh( a_ * u - i * b_)));
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

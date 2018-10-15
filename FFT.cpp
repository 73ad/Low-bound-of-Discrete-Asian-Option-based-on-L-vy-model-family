//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    OptionFix.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "OptionFix.h"

#include "Input.h"

#include "PseudoFactory.h"

#include "FFT.h"

#include <vector>
#include <iomanip>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    interface
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

FFT::FFT(Input& inp, PseudoFactory& fac)
:   nSamples_(inp.GetNSample())
,   SampleRange_(inp.GetSampleRange())
{
    opt_ = fac.CreatOpt();
}

void FFT::separate(std::complex<double> *a, int n)
{
    std::complex<double>* b = new std::complex<double>[n / 2];  // get temp heap storage
    for (int i = 0; i < n / 2; i++)
    {// copy all odd elements to heap storage
        b[i] = a[i * 2 + 1];
    }
    for (int i = 0; i < n / 2; i++)    // copy all even elements to lower-half of a[]
    {
        a[i] = a[i * 2];
    }
    for (int i = 0; i < n / 2; i++)    // copy all odd (from heap) to upper-half of a[]
    {
        a[i + n / 2] = b[i];
    }
    delete[] b;                 // delete heap storage
}

void FFT::fft2(std::complex<double> *X, int N)
{
    if (N < 2)
    {
            // bottom of recursion.
            // Do nothing here, because already X[0] = x[0]
    }
    else
    {
        separate(X, N);      // all evens to lower half, all odds to upper half
        fft2(X, N / 2);   // recurse even items
        fft2(X + N / 2, N / 2);   // recurse odd  items
            // combine results of two half recursions
        for (int k = 0; k<N / 2; k++)
        {
            std::complex<double> e = X[k];   // even
            std::complex<double> o = X[k + N / 2];   // odd
            // w is the "twiddle-factor"
            std::complex<double> w = exp(std::complex<double>(0, -2.* M_PI * k / N));
            X[k] = e + w * o;
            X[k + N / 2] = e - w * o;
        }
       
    }
}

void FFT::FastFT()
{
    double freq = SampleRange_ / (double)nSamples_;
    std::complex<double> X[nSamples_];// storage for FFT answer

    // generate samples for testing
    
    X[nSamples_] = std::complex<double>(0., 0.);
    double delta = 1.0;     //  the value of delta will be different in different models
    
    for (int i = 0; i < nSamples_; ++i)
    {
        double u = (double)i / freq ;
        X[i] = opt_->option(u, delta);;        // copy into X[] for FFT work & result
        std::cout<<X[i]<<std::endl;
    }
    // compute fft for this data
    fft2(X, nSamples_);
    double temp = 10;
    int m;
    for (int i = 1; i < nSamples_; ++i )
    {
    	if (abs(X[i]) > temp)
		{
    		m = i;
			temp = abs(X[i]);
		}
        std::cout << "sequence:" << i * freq << "dd:" << X[i] <<"mo:" << 2.0 * abs(X[i])/ (double)nSamples_ << std::endl;
    }
    std::cout << "location:" << m * freq << "mo:" << temp * 2.0 / (double)nSamples_ << std::endl;
     
        
        
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

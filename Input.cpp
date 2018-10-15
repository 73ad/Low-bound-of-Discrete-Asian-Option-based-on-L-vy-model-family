//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Input.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "Input.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	interface
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Input::Input()
{
    S_0_ = 100;
    r_ = 0.05;
    q_ = 0;
    T_ = 1;
    K_ = 90; //strike price
    N_ = 12; //timstep
   
    //Underlying Asset Model types
    UM_type_ = 'G'; // G for Gaussian model, V for VG model, and so on ......
    //Process type
    P_type_ = 'l'; // 'l' for Levy process, 'a' for ASV process, 'c' for CEV process
    //Option type
    O_type_ = 'x'; // 'x' for fixed asian option, 'l' for float asian option
    //FFT Parameters
    nSamples_ = 256;
    SampleRange_ = 8.0;
    //Gaussian Parameters
    double g_sigma_ = 0.17801;
   
    //VG Parameters
    double vg_v_ = 0.736703;
    double vg_theta_ = -0.136105;
    double vg_sig_ = 0.180022;
   
   //NIG Parameters
   double nig_a_ = 6.1882;
   double nig_b_ = -3.8941;
   double nig_delta_ = 0.1622;
   
   //CGMY Parameters
   double cgmy_c_ = 0.0244;
   double cgmy_g_ = 0.0765;
   double cgmy_m_ = 7.5515;
   double cgmy_y_ = 1.2945;
   
   //MJD Parameters
   double mjd_sigma_ = 0.126349;
   double mjd_l_ = 0.178414;
   double mjd_mux_ = -0.390078;
   double mjd_sigx_ = 0.338796;
   
   //DEJD Parameters
   double dejd_sigma_ = 0.120381;
   double dejd_l_ = 0.330966;
   double dejd_p_ = 0.20761;
   double dejd_n1_ = 9.65997;
   double dejd_n2_ = 3.13868;
   
   //Meixner Parameters
   double mei_a_ = 0.3977;
   double mei_b_ = -1.494;
   double mei_delta_ = 0.3462;
   
   //Heston Parameters
   double hes_alpha_ = 6.21;
   double hes_beta_ = 0.019;
   double hes_gamma_ = 0.61;
   double hes_pho_ = -0.7;
   double hes_v0_ = 0.101;
   
   //Bates Parameters
   double b_alpha_ = 3.99;
   double b_beta_ = 0.014;
   double b_gamma_ = 0.27;
   double b_pho_ = -0.79;
   double b_v0_ = 0.094;
   double b_l_ = 0.11;
   double b_mux_ = -0.1391;
   double b_sigx_ = 0.15;
   
   //DPS Parameters
   double dps_alpha_ = 3.46;
   double dps_beta_ = 0.008;
   double dps_gamma_ = 0.14;
   double dps_pho_ = -0.82;
   double dps_v0_ = 0.087;
   double dps_l_ = 0.47;
   double dps_mux_ = -0.0865;
   double dps_sigx_ = 0.00001;
   double dps_muv_ = 0.05;
   double dps_phoxv_ = -0.38;
   
   //BNS-Gamma parameters
   double bns1_l_ = 1.6787;
   double bns1_v_ = 1.0071;
   double bns1_alpha_ = 116.01;
   double bns1_pho_ = -4.4617;
   double bns1_v0_ = 0.065883;
   
   //BNS-IG Parameters
   double bns2_l_ = 2.4958;
   double bns2_v_ = 0.0872;
   double bns2_alpha_ = 11.98;
   double bns2_pho_ = -4.7039;
   double bns2_v0_ = 0.064262;
   
   
}
  
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

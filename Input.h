//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Input.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef InputH
#define InputH
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  class Input
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Input
{
    public:
        Input();
        
        double GetS0() const {return S_0_ ;}
        double Getr() const {return r_;}
        double Getq() const {return q_;}
        double GetK() const {return K_;}
        double GetT() const {return T_;}
        int GetN() const {return N_;} 
        
        //Underlying Asset Model types
        char GetUAMtype() const {return UM_type_;} 
        //Process type
        char GetPtype() const {return P_type_;}
        //Option type
        char GetOtype() const {return O_type_;}
        //FFT parameters
        int GetNSample() const {return nSamples_;}
        double GetSampleRange() const {return SampleRange_;}
		//Gaussian Parameters
        double Getg_sigma() const {return g_sigma_ ;}
        
        //VG Parameters
        double Getvg_v() const {return vg_v_;}
		double Getvg_theta() const {return vg_theta_;}
        double Getvg_sig() const {return vg_sig_;}
        
        //NIG Parameters
        double Getnig_a() const {return nig_a_;}
        double Getnig_b() const {return nig_b_;}
        double Getnig_delta() const {return nig_delta_;}
        
        //CGMY Parameters
        double Getcgmy_c() const {return cgmy_c_;}
        double Getcgmy_g() const {return cgmy_g_;}
        double Getcgmy_m() const {return cgmy_m_;}
        double Getcgmy_y() const {return cgmy_y_;}
        
        //MJD Parameters
        double Getmjd_sigma() const {return mjd_sigma_;}
        double Getmjd_l() const {return mjd_l_;}
        double Getmjd_mux() const {return mjd_mux_;}
        double Getmjd_sigx() const {return mjd_sigx_;}
        
        //DEJD Parameters
        double Getdejd_sigma() const {return dejd_sigma_;}
        double Getdejd_l() const {return dejd_l_;}
        double Getdejd_p() const {return dejd_p_;}
        double Getdejd_n1() const {return dejd_n1_;}
        double Getdejd_n2() const {return dejd_n2_;}
		
		//Meixner Parameters
		double Getmei_a() const {return mei_a_;}
        double Getmei_b() const {return mei_b_;}
        double Getmei_delta() const {return mei_delta_;}
		
		//Heston Parameters
		double Gethes_alpha() const {return hes_alpha_;}
		double Gethes_beta() const {return hes_beta_;}
		double Gethes_gamma() const {return hes_gamma_;}
		double Gethes_pho() const {return hes_pho_;}
		double Gethes_v0() const {return hes_v0_;}
		
		//Bates Parameters
		double Getb_alpha() const {return b_alpha_;}
		double Getb_beta() const {return b_beta_;}
		double Getb_gamma() const {return b_gamma_;}
		double Getb_pho() const {return b_pho_;}
		double Getb_v0() const {return b_v0_;}
		double Getb_l() const {return b_l_;}
		double Getb_mux() const {return b_mux_;}
		double Getb_sigx() const {return b_sigx_;}
   
        //DPS Parameters
        double Getdps_alpha() const {return b_alpha_;}
		double Getdps_beta() const {return dps_beta_;}
		double Getdps_gamma() const {return dps_gamma_;}
		double Getdps_pho() const {return dps_pho_;}
		double Getdps_v0() const {return dps_v0_;}
		double Getdps_l() const {return dps_l_;}
		double Getdps_mux() const {return dps_mux_;}
		double Getdps_sigx() const {return dps_sigx_;}
		double Getdps_muv() const {return dps_muv_;}
		double Getdps_phoxv() const {return dps_phoxv_;}
        
        //BNS-Gamma parameters
        double Getbns1_l() const {return bns1_l_;}
		double Getbns1_v() const {return bns1_v_;}
		double Getbns1_alpha() const {return bns1_alpha_;}
		double Getbns1_pho() const {return bns1_pho_;}
		double Getbns1_v0() const {return bns1_v0_;}
   
        //BNS-IG Parameters
        double Getbns2_l() const {return bns2_l_;}
		double Getbns2_v() const {return bns2_v_;}
		double Getbns2_alpha() const {return bns2_alpha_;}
		double Getbns2_pho() const {return bns2_pho_;}
		double Getbns2_v0() const {return bns2_v0_;}
        
                
    private:
        double S_0_;
        double r_;
        double q_;
        double K_;
        double T_;
        int N_;
        
        //Underlying Asset Model types
        char UM_type_;
        //Process type
        char P_type_;
        //Option type
        char O_type_;
    
        //FFT Parameters
        int nSamples_;
        double SampleRange_;
        //Gaussian Parameters
		double g_sigma_;
		
		//VG Parameters
        double vg_v_;
        double vg_theta_;
        double vg_sig_; 
   
        //NIG Parameters
        double nig_a_;
        double nig_b_;
		double nig_delta_;
   
	   //CGMY Parameters
	   double cgmy_c_;
	   double cgmy_g_;
	   double cgmy_m_;
	   double cgmy_y_;
	   
	   //MJD Parameters
	   double mjd_sigma_;
	   double mjd_l_;
	   double mjd_mux_;
	   double mjd_sigx_;
	   
	   //DEJD Parameters
	   double dejd_sigma_;
	   double dejd_l_;
	   double dejd_p_;
	   double dejd_n1_;
	   double dejd_n2_;
	   
	   //Meixner Parameters
	   double mei_a_;
	   double mei_b_;
	   double mei_delta_;
	   
	   //Heston Parameters
	   double hes_alpha_;
	   double hes_beta_;
	   double hes_gamma_;
	   double hes_pho_;
	   double hes_v0_;
	   
	   //Bates Parameters
	   double b_alpha_;
	   double b_beta_;
	   double b_gamma_;
	   double b_pho_;
	   double b_v0_;
	   double b_l_;
	   double b_mux_;
	   double b_sigx_;
	   
	   //DPS Parameters
	   double dps_alpha_;
	   double dps_beta_;
	   double dps_gamma_;
	   double dps_pho_;
	   double dps_v0_ ;
	   double dps_l_;
	   double dps_mux_;
	   double dps_sigx_;
	   double dps_muv_;
	   double dps_phoxv_;
	   
	   //BNS-Gamma parameters
	   double bns1_l_;
	   double bns1_v_;
	   double bns1_alpha_;
	   double bns1_pho_;
	   double bns1_v0_;
	   
	   //BNS-IG Parameters
	   double bns2_l_;
	   double bns2_v_;
	   double bns2_alpha_;
	   double bns2_pho_;
	   double bns2_v0_;
		
};

// CONTAIN INPUT.H AND INPUT & INP IN THE CONSTRUCTURE

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#endif
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

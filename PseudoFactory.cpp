//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    PseudoFactory.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "PseudoFactory.h"

#include "Input.h"

#include "UAModelBase.h"
#include "UAModelGaussian.h"
#include "UAModelCGMY.h"
#include "UAModelDEJD.h"
#include "UAModelMJD.h"
#include "UAModelMeixner.h"
#include "UAModelNIG.h"
#include "UAModelVG.h"

#include "AverageBase.h"
#include "AverageLEVY.h"

#include "OptionBase.h"
#include "OptionFix.h"

#include <stdexcept>

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    getters
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


char PseudoFactory::GetUAMtype() const {return inp_->GetUAMtype();}
char PseudoFactory::GetPtype() const {return inp_->GetPtype();}
char PseudoFactory::GetOtype() const {return inp_->GetOtype();}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    CreateUnderlyingAssetModel
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

UAModelBase * PseudoFactory::CreateUAM()
{
    char um_type = inp_->GetUAMtype();
    
    switch(um_type)
    {
        case 'G':	return new UAModelGaussian(*inp_);          break;
        case 'Y':	return new UAModelCGMY(*inp_);				break;
        case 'D':	return new UAModelDEJD(*inp_);				break;
        case 'J':	return new UAModelMJD(*inp_);				break;
        case 'M':	return new UAModelMeixner(*inp_);			break;
        case 'N':	return new UAModelNIG(*inp_);				break;
        case 'V':	return new UAModelVG(*inp_);				break;
    
        default: throw std::runtime_error("PseudoFactory::CreateUM:  Bad character");
    }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    CreateAverageModel
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
AverageBase * PseudoFactory::CreateAVE()
{
    char p_type = inp_->GetPtype();
    
    switch(p_type)
    {
        case 'l':  return new AverageLEVY(*inp_, *this);           break;
            
        default: throw std::runtime_error("PseudoFactory::CreateAVE:  Bad character");
    }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    CreateOption
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
OptionBase * PseudoFactory::CreatOpt()
{
    char o_type = inp_->GetOtype();
    
    switch(o_type)
    {
        case 'x':  return new OptionFix(*inp_, *this);        break;
            
        default: throw std::runtime_error("PseudoFactory::CreateOption:  Bad character");
    }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//    end
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

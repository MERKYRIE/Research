#include"Research.hxx"

namespace NResearch::NResearch::NMouse
{
    SPixel::SPixel()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
    }

    SPixel* SPixel::IPreupdate()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
        return(this);
    }

    SPixel* SPixel::IPostupdate(double const& AX , double const& AY)
    {
        FModification = true;
        FX = AX;
        FY = AY;
        return(this);
    }

    SPixel::~SPixel()
    {
    
    }
}
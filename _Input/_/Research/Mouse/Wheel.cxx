#include"Research.hxx"

namespace NResearch::NResearch::NMouse
{
    SWheel::SWheel()
    {
        FModification = false;
        FState = 0;
    }

    SWheel* SWheel::IPreupdate()
    {
        FModification = false;
        FState = 0;
        return(this);
    }

    SWheel* SWheel::IPostupdate(SDL_MouseWheelEvent const& AWheel)
    {
        FModification = true;
        FState = AWheel.y;
        return(this);
    }

    SWheel::~SWheel()
    {
    
    }
}
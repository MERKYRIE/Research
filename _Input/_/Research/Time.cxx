#include"Research.hxx"

namespace NResearch::NResearch
{
    void STime::IUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks();
        FRelative = FAbsolute - FLast;
    }
}
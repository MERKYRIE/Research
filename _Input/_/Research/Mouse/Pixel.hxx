#pragma once

namespace NResearch::NResearch::NMouse
{
    struct SPixel
    {
        bool FModification;
        double FX;
        double FY;

        SPixel();
        SPixel* IPreupdate();
        SPixel* IPostupdate(double const& AX , double const& AY);
        ~SPixel();
    };
}
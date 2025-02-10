#pragma once

namespace NResearch::NResearch
{
    inline struct STime
    {
        double FLast;
        double FAbsolute;
        double FRelative;

        void IUpdate();
    }
    GTime;
}
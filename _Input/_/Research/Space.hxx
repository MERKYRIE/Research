#pragma once

namespace NResearch::NResearch
{
    inline struct SSpace
    {
        double FX;
        double FY;
        double FSpeedX;
        double FSpeedY;
        std::int64_t FIterationX;
        std::int64_t FIterationY;
        std::int64_t FWidth;
        std::int64_t FHeight;
        double FScaleX;
        double FScaleY;
        double FScaleLastX;
        double FScaleLastY;
        double FScaleXMinimum;
        double FScaleXMaximum;
        double FScaleYMinimum;
        double FScaleYMaximum;
        double FScalingX;
        double FScalingY;
        std::shared_ptr<NSpace::SImage> FImage;
        std::vector<std::vector<std::shared_ptr<NSpace::SPartition>>> FMatrix;

        SSpace();
        void IUpdate();
    }
    GSpace;
}
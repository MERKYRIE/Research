#pragma once

namespace NResearch::NResearch
{
    //Naive tilemap implementation

    struct SSpace1
    {
        //Configures viewport's mouse dragging speed

        double FSpeedX;
        double FSpeedY;

        //Configures viewport's wheel scrolling scale

        double FScaleXMinimum;
        double FScaleXMaximum;

        //Configures viewport's horizontal scale limits

        double FScaleYMinimum;
        double FScaleYMaximum;

        //Configures viewport's vertical scale limits

        double FScalingX;
        double FScalingY;

        //Configures partitions's displacement within matrix

        std::int64_t FWidth;
        std::int64_t FHeight;

        //Contains all partitions as layout

        std::vector<std::vector<std::shared_ptr<NSpace1::SPartition>>> FMatrix;

        //Configures viewport and all partitions

        SSpace1();

        //Updates viewport and all partitions

        void IUpdate();
    };
}
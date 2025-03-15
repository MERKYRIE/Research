#pragma once

namespace NResearch::NResearch
{
    //Optimized tilemap implementation
    //Remove function parameters in calls to tilemap's partitions for performance upgrade
    //Replace std::shared_ptr usages with std::unique_ptr ones for memory upgrade
    //Separate ground structures and entity ones for performance upgrade
    //Move ground and entity image here for memory upgrade

    inline struct SSpace6
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

        //Configures viewport's current respective coordinates
        //Move here as global to directly pass as function parameters in calls to tilemap's partitions
        
        double FX;
        double FY;

        //Configures viewport's current respective scale
        //Move here as global to directly pass as function parameters in calls to tilemap's partitions

        double FScaleX;
        double FScaleY;

        //Configures viewport's last respective scale
        //Move here as global to directly pass as function parameters in calls to tilemap's partitions

        double FScaleLastX;
        double FScaleLastY;

        //Configures tilemap's current respective partition
        //Move here as global to directly pass as function parameters in calls to tilemap's partitions

        std::int64_t FIterationX;
        std::int64_t FIterationY;

        //Contains all partitions as layout
        //Replace std::shared_ptr usages with std::unique_ptr
        //Separate ground structures and entity

        std::vector<std::vector<std::unique_ptr<NSpace6::SGround>>> FGrounds;

        //Contains all partitions as layout
        //Replace std::shared_ptr usages with std::unique_ptr
        //Separate ground structures and entity

        std::unordered_map<std::int64_t , std::unordered_map<std::int64_t , std::unique_ptr<NSpace6::SEntity>>> FEntities;

        //Move ground and entity image
        
        std::unique_ptr<NSpace6::SImage> FImage;
        
        //Configures viewport and all partitions

        SSpace6();

        //Updates viewport and all partitions

        void IUpdate();
    }
    GSpace;
}
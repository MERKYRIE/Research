#pragma once

namespace NResearch::NResearch::NSpace2
{
    //Optimized entity implementation
    //Remove function parameters in calls to tilemap's partitions for performance upgrade
    
    struct SEntity
    {
        //Contains image necessary to draw
        
        std::shared_ptr<SImage> FImage;

        //Configures image to cache it
        
        SEntity();

        //Updates position, scale and draws
        //Remove function parameters

        void IUpdate();
    };
}
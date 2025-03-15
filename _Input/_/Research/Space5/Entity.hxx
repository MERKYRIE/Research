#pragma once

namespace NResearch::NResearch::NSpace5
{
    //Optimized entity implementation
    //Remove function parameters in calls to tilemap's partitions for performance upgrade
    //Replace std::shared_ptr usages with std::unique_ptr usages for memory upgrade
    
    struct SEntity
    {
        //Contains image necessary to draw
        //Replace std::shared_ptr usages with std::unique_ptr
        
        std::unique_ptr<SImage> FImage;

        //Configures image to cache it
        
        SEntity();

        //Updates position, scale and draws
        //Remove function parameters

        void IUpdate();
    };
}
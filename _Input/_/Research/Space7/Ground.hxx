#pragma once

namespace NResearch::NResearch::NSpace7
{
    //Optimized ground implementation
    //Remove function parameters in calls to tilemap's partitions for performance upgrade
    //Replace std::shared_ptr usages with std::unique_ptr usages for memory upgrade
    //Move ground and entity image here for memory upgrade
    //Move ground and entity image loading for permormance upgrade
    
    struct SGround
    {
        //Updates position, scale and draws
        //Remove function parameters

        void IUpdate();
    };
}
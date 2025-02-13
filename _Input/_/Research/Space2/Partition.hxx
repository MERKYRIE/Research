#pragma once

namespace NResearch::NResearch::NSpace2
{
    //Optimized partition implementation
    //Remove function parameters in calls to tilemap's partitions for performance upgrade
    
    struct SPartition
    {
        //Contains ground as lower part
        
        std::shared_ptr<SGround> FGround;

        //Contains entity as upper part

        std::shared_ptr<SEntity> FEntity;

        //Updates both parts checking existance
        //Remove function parameters

        void IUpdate();
    };
}
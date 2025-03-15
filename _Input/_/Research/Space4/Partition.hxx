#pragma once

namespace NResearch::NResearch::NSpace4
{
    //Optimized partition implementation
    //Remove function parameters in calls to tilemap's partitions for performance upgrade
    //Replace std::shared_ptr usages with std::unique_ptr usages for memory upgrade
    //Remove checking of ground pointer validity for performance upgrade
    
    struct SPartition
    {
        //Contains ground as lower part
        //Replace std::shared_ptr usages with std::unique_ptr
        
        std::unique_ptr<SGround> FGround;

        //Contains entity as upper part
        //Replace std::shared_ptr usages with std::unique_ptr

        std::unique_ptr<SEntity> FEntity;

        //Updates both parts checking existance
        //Remove function parameters

        void IUpdate();
    };
}
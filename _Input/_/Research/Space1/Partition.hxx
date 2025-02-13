#pragma once

namespace NResearch::NResearch::NSpace1
{
    //Naive partition implementation
    
    struct SPartition
    {
        //Contains ground as lower part
        
        std::shared_ptr<NSpace1::SGround> FGround;

        //Contains entity as upper part

        std::shared_ptr<NSpace1::SEntity> FEntity;

        //Updates both parts checking existance

        void IUpdate(double AX , double AY , std::int64_t AIterationX , std::int64_t AIterationY , double AScaleX , double AScaleY);
    };
}
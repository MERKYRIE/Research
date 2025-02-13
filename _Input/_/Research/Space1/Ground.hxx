#pragma once

namespace NResearch::NResearch::NSpace1
{
    //Naive ground implementation
    
    struct SGround
    {
        //Contains image necessary to draw
        
        std::shared_ptr<SImage> FImage;
        
        //Configures image to cache it

        SGround();

        //Updates position, scale and draws

        void IUpdate(double AX , double AY , std::int64_t AIterationX , std::int64_t AIterationY , double AScaleX , double AScaleY);
    };
}
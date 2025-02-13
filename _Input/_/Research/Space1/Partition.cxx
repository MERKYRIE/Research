#include"Research.hxx"

namespace NResearch::NResearch::NSpace1
{
    void SPartition::IUpdate(double AX , double AY , std::int64_t AIterationX , std::int64_t AIterationY , double AScaleX , double AScaleY)
    {
        if(FGround)
        {
            FGround->IUpdate(AX , AY , AIterationX , AIterationY , AScaleX , AScaleY);
        }
        if(FEntity)
        {
            FEntity->IUpdate(AX , AY , AIterationX , AIterationY , AScaleX , AScaleY);
        }
    }
}
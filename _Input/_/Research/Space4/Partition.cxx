#include"Research.hxx"

namespace NResearch::NResearch::NSpace4
{
    void SPartition::IUpdate()
    {
        FGround->IUpdate();
        if(FEntity)
        {
            FEntity->IUpdate();
        }
    }
}
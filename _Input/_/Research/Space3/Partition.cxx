#include"Research.hxx"

namespace NResearch::NResearch::NSpace3
{
    void SPartition::IUpdate()
    {
        if(FGround)
        {
            FGround->IUpdate();
        }
        if(FEntity)
        {
            FEntity->IUpdate();
        }
    }
}
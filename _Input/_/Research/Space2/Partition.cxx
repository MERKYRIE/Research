#include"Research.hxx"

namespace NResearch::NResearch::NSpace2
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
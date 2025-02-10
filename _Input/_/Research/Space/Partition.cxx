#include"Research.hxx"

namespace NResearch::NResearch::NSpace
{
    void SPartition::IUpdate()
    {
        FTerrain->IUpdate();
        if(FEntity)
        {
            FEntity->IUpdate();
        }
    }
}
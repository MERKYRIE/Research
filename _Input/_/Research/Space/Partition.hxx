#pragma once

namespace NResearch::NResearch::NSpace
{
    struct SPartition
    {
        std::shared_ptr<NSpace::STerrain> FTerrain;
        std::shared_ptr<NSpace::SEntity> FEntity;

        void IUpdate();
    };
}
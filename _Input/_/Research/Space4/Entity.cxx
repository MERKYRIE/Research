#include"Research.hxx"

namespace NResearch::NResearch::NSpace4
{
    SEntity::SEntity()
    {
        FImage = std::make_unique<SImage>();
        FImage->ILoad(GVideo.IFont("/Consolas.ttf")->IString("Entity"));
    }
    
    void SEntity::IUpdate()
    {
        FImage->IDestinationXSquareAbsolute(GSpace.FScaleX * (-GSpace.FX + GSpace.FIterationX));
        FImage->IDestinationYSquareAbsolute(GSpace.FScaleY * (-GSpace.FY + GSpace.FIterationY));
        FImage->IDestinationWidthSquareAbsolute(GSpace.FScaleX);
        FImage->IDestinationHeightSquareAbsolute(GSpace.FScaleY);
        FImage->IDraw();
    }
}
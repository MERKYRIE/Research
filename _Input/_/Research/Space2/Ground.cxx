#include"Research.hxx"

namespace NResearch::NResearch::NSpace2
{
    SGround::SGround()
    {
        FImage = std::make_shared<SImage>();
        FImage->ILoad(GVideo.IFont("/Consolas.ttf")->IString("Ground"));
    }
    
    void SGround::IUpdate()
    {
        FImage->IDestinationXSquareAbsolute(GSpace.FScaleX * (-GSpace.FX + GSpace.FIterationX));
        FImage->IDestinationYSquareAbsolute(GSpace.FScaleY * (-GSpace.FY + GSpace.FIterationY));
        FImage->IDestinationWidthSquareAbsolute(GSpace.FScaleX);
        FImage->IDestinationHeightSquareAbsolute(GSpace.FScaleY);
        FImage->IDraw();
    }
}
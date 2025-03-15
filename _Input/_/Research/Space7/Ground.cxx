#include"Research.hxx"

namespace NResearch::NResearch::NSpace7
{
    void SGround::IUpdate()
    {
        GSpace.FImage->IDestinationXSquareAbsolute(GSpace.FScaleX * (-GSpace.FX + GSpace.FIterationX));
        GSpace.FImage->IDestinationYSquareAbsolute(GSpace.FScaleY * (-GSpace.FY + GSpace.FIterationY));
        GSpace.FImage->IDestinationWidthSquareAbsolute(GSpace.FScaleX);
        GSpace.FImage->IDestinationHeightSquareAbsolute(GSpace.FScaleY);
        GSpace.FImage->IDraw();
    }
}
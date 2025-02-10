#include"Research.hxx"

namespace NResearch::NResearch::NSpace
{
    void STerrain::IUpdate()
    {
        GSpace.FImage->ILoad(GVideo.IFont("/Consolas.ttf")->IString("Terrain"));
        GSpace.FImage->IDestinationXSquareAbsolute(GSpace.FScaleX * (-GSpace.FX + GSpace.FIterationX));
        GSpace.FImage->IDestinationYSquareAbsolute(GSpace.FScaleY * (-GSpace.FY + GSpace.FIterationY));
        GSpace.FImage->IDestinationWidthSquareAbsolute(GSpace.FScaleX);
        GSpace.FImage->IDestinationHeightSquareAbsolute(GSpace.FScaleY);
        GVideo.IFont("/Consolas.ttf")->IString("Terrain")->IDraw(GSpace.FImage->FSource , GSpace.FImage->FDestination);
    }
}
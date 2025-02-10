#include"Research.hxx"

namespace NResearch::NResearch
{
    SSpace::SSpace()
    {
        FX = 0.0;
        FY = 0.0;
        FSpeedX = 0.0025;
        FSpeedY = 0.0025;
        FIterationX = 0;
        FIterationY = 0;
        FWidth = 10;
        FHeight = 10;
        FScaleX = 0.05;
        FScaleY = 0.05;
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
        FScaleXMinimum = 0.05;
        FScaleXMaximum = 0.2;
        FScaleYMinimum = 0.05;
        FScaleYMaximum = 0.2;
        FScalingX = 2.0;
        FScalingY = 2.0;
        FImage = std::make_shared<NSpace::SImage>();
        FMatrix.resize(FWidth);
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            FMatrix[FIterationX].resize(FHeight);
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FMatrix[FIterationX][FIterationY] = std::make_shared<NSpace::SPartition>();
                FMatrix[FIterationX][FIterationY]->FTerrain = std::make_shared<NSpace::STerrain>();
            }
            FMatrix[FIterationX].shrink_to_fit();
        }
        FMatrix.shrink_to_fit();
        FMatrix[0][0]->FEntity = std::make_shared<NSpace::SEntity>();
    }

    void SSpace::IUpdate()
    {
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
        FScaleX = std::clamp(FScaleX * std::pow(FScalingX , GMouse.FWheel->FState) , FScaleXMinimum , FScaleXMaximum);
        FScaleY = std::clamp(FScaleY * std::pow(FScalingY , GMouse.FWheel->FState) , FScaleYMinimum , FScaleYMaximum);
        FX -= FSpeedX * GMouse.FButtons["Middle"]->FHeld->FRelative->FPixel->FX / FScaleLastX - (FScaleLastX != FScaleX) * GMouse.FWheel->FState * GMouse.FCursor->FAbsolute->FSquare->FX / std::max(FScaleLastX , FScaleX);
        FY -= FSpeedY * GMouse.FButtons["Middle"]->FHeld->FRelative->FPixel->FY / FScaleLastY - (FScaleLastY != FScaleY) * GMouse.FWheel->FState * GMouse.FCursor->FAbsolute->FSquare->FY / std::max(FScaleLastY , FScaleY);
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FMatrix[FIterationX][FIterationY]->IUpdate();
            }
        }
    }
}
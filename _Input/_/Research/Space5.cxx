#include"Research.hxx"

namespace NResearch::NResearch
{
    SSpace5::SSpace5()
    {
        FSpeedX = 0.0025;
        FSpeedY = 0.0025;
        FScaleXMinimum = 0.05;
        FScaleXMaximum = 0.2;
        FScaleYMinimum = 0.05;
        FScaleYMaximum = 0.2;
        FScalingX = 2.0;
        FScalingY = 2.0;
        FWidth = 10;
        FHeight = 10;
        FGrounds.resize(FWidth);
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            FGrounds[FIterationX].resize(FHeight);
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FGrounds[FIterationX][FIterationY] = std::make_unique<NSpace5::SGround>();
            }
            FGrounds[FIterationX].shrink_to_fit();
        }
        FGrounds.shrink_to_fit();
        FEntities[0][0] = std::make_unique<NSpace5::SEntity>();
        FX = 0.0;
        FY = 0.0;
        FScaleX = 0.05;
        FScaleY = 0.05;
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
    }

    void SSpace5::IUpdate()
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
                FGrounds[FIterationX][FIterationY]->IUpdate();
            }
        }
        for(auto const& [LX , LEntities] : FEntities)
        {
            for(auto const& [LY , LEntity] : LEntities)
            {
                FIterationX = LX;
                FIterationY = LY;
                LEntity->IUpdate();
            }
        }
    }
}
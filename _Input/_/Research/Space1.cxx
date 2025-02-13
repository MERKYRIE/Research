#include"Research.hxx"

namespace NResearch::NResearch
{
    SSpace1::SSpace1()
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
        FMatrix.resize(FWidth);
        for(std::int64_t LIterationX{0} ; LIterationX < FWidth ; LIterationX++)
        {
            FMatrix[LIterationX].resize(FHeight);
            for(std::int64_t LIterationY{0} ; LIterationY < FHeight ; LIterationY++)
            {
                FMatrix[LIterationX][LIterationY] = std::make_shared<NSpace1::SPartition>();
                FMatrix[LIterationX][LIterationY]->FGround = std::make_shared<NSpace1::SGround>();
            }
            FMatrix[LIterationX].shrink_to_fit();
        }
        FMatrix.shrink_to_fit();
        FMatrix[0][0]->FEntity = std::make_shared<NSpace1::SEntity>();
    }

    void SSpace1::IUpdate()
    {
        static double LX{0.0};
        static double LY{0.0};
        static double LScaleX{0.05};
        static double LScaleY{0.05};
        static double LScaleLastX{LScaleX};
        static double LScaleLastY{LScaleY};
        LScaleLastX = LScaleX;
        LScaleLastY = LScaleY;
        LScaleX = std::clamp(LScaleX * std::pow(FScalingX , GMouse.FWheel->FState) , FScaleXMinimum , FScaleXMaximum);
        LScaleY = std::clamp(LScaleY * std::pow(FScalingY , GMouse.FWheel->FState) , FScaleYMinimum , FScaleYMaximum);
        LX -= FSpeedX * GMouse.FButtons["Middle"]->FHeld->FRelative->FPixel->FX / LScaleLastX - (LScaleLastX != LScaleX) * GMouse.FWheel->FState * GMouse.FCursor->FAbsolute->FSquare->FX / std::max(LScaleLastX , LScaleX);
        LY -= FSpeedY * GMouse.FButtons["Middle"]->FHeld->FRelative->FPixel->FY / LScaleLastY - (LScaleLastY != LScaleY) * GMouse.FWheel->FState * GMouse.FCursor->FAbsolute->FSquare->FY / std::max(LScaleLastY , LScaleY);
        for(std::int64_t LIterationX{0} ; LIterationX < FWidth ; LIterationX++)
        {
            for(std::int64_t LIterationY{0} ; LIterationY < FHeight ; LIterationY++)
            {
                FMatrix[LIterationX][LIterationY]->IUpdate(LX , LY , LIterationX , LIterationY , LScaleX , LScaleY);
            }
        }
    }
}
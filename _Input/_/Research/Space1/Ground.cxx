#include"Research.hxx"

namespace NResearch::NResearch::NSpace1
{
    SGround::SGround()
    {
        FImage = std::make_shared<NSpace1::SImage>();
        FImage->ILoad(GVideo.IFont("/Consolas.ttf")->IString("Ground"));
    }
    
    void SGround::IUpdate(double AX , double AY , std::int64_t AIterationX , std::int64_t AIterationY , double AScaleX , double AScaleY)
    {
        FImage->IDestinationXSquareAbsolute(AScaleX * (-AX + AIterationX));
        FImage->IDestinationYSquareAbsolute(AScaleY * (-AY + AIterationY));
        FImage->IDestinationWidthSquareAbsolute(AScaleX);
        FImage->IDestinationHeightSquareAbsolute(AScaleY);
        FImage->IDraw();
    }
}
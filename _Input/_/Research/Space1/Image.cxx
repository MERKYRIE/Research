#include"Research.hxx"

namespace NResearch::NResearch::NSpace1
{
    SImage::SImage()
    {
        FImage = nullptr;
        FSource = {};
        FDestination = {};
    }

    void SImage::ILoad(NVideo1::SImage* const& AImage)
    {
        FImage = AImage;
        FSource = {0 , 0 , static_cast<std::int32_t>(std::round(FImage->IWidth())) , static_cast<std::int32_t>(std::round(FImage->IHeight()))};
    }

    void SImage::IUnload()
    {
        FImage = nullptr;
        FSource = {};
    }

    double SImage::ISourceX()
    {
        return(FSource.x);
    }

    double SImage::ISourceY()
    {
        return(FSource.y);
    }

    double SImage::ISourceWidth()
    {
        return(FSource.w);
    }

    double SImage::ISourceHeight()
    {
        return(FSource.h);
    }

    void SImage::ISourceXAbsolute(double const& AX)
    {
        FSource.x = static_cast<std::int32_t>(std::round(AX));
    }

    void SImage::ISourceYAbsolute(double const& AY)
    {
        FSource.y = static_cast<std::int32_t>(std::round(AY));
    }

    void SImage::ISourceWidthAbsolute(double const& AWidth)
    {
        FSource.w = static_cast<std::int32_t>(std::round(AWidth));
    }

    void SImage::ISourceHeightAbsolute(double const& AHeight)
    {
        FSource.h = static_cast<std::int32_t>(std::round(AHeight));
    }

    void SImage::ISourceXRelative(double const& AX)
    {
        FSource.x += static_cast<std::int32_t>(std::round(AX));
    }

    void SImage::ISourceYRelative(double const& AY)
    {
        FSource.y += static_cast<std::int32_t>(std::round(AY));
    }

    void SImage::ISourceWidthRelative(double const& AWidth)
    {
        FSource.w += static_cast<std::int32_t>(std::round(AWidth));
    }

    void SImage::ISourceHeightRelative(double const& AHeight)
    {
        FSource.h += static_cast<std::int32_t>(std::round(AHeight));
    }

    double SImage::ISourceXRectangle()
    {
        return(FSource.x / FImage->IWidth());
    }

    double SImage::ISourceYRectangle()
    {
        return(FSource.y / FImage->IHeight());
    }

    double SImage::ISourceWidthRectangle()
    {
        return(FSource.w / FImage->IWidth());
    }

    double SImage::ISourceHeightRectangle()
    {
        return(FSource.h / FImage->IHeight());
    }

    void SImage::ISourceXRectangleAbsolute(double const& AX)
    {
        FSource.x = static_cast<std::int32_t>(std::round(FImage->IWidth() * AX));
    }

    void SImage::ISourceYRectangleAbsolute(double const& AY)
    {
        FSource.y = static_cast<std::int32_t>(std::round(FImage->IHeight() * AY));
    }

    void SImage::ISourceWidthRectangleAbsolute(double const& AWidth)
    {
        FSource.w = static_cast<std::int32_t>(std::round(FImage->IWidth() * AWidth));
    }

    void SImage::ISourceHeightRectangleAbsolute(double const& AHeight)
    {
        FSource.h = static_cast<std::int32_t>(std::round(FImage->IHeight() * AHeight));
    }

    void SImage::ISourceXRectangleRelative(double const& AX)
    {
        FSource.x += static_cast<std::int32_t>(std::round(FImage->IWidth() * AX));
    }

    void SImage::ISourceYRectangleRelative(double const& AY)
    {
        FSource.y += static_cast<std::int32_t>(std::round(FImage->IHeight() * AY));
    }

    void SImage::ISourceWidthRectangleRelative(double const& AWidth)
    {
        FSource.w += static_cast<std::int32_t>(std::round(FImage->IWidth() * AWidth));
    }

    void SImage::ISourceHeightRectangleRelative(double const& AHeight)
    {
        FSource.h += static_cast<std::int32_t>(std::round(FImage->IHeight() * AHeight));
    }

    double SImage::ISourceXSquare()
    {
        return(FSource.x / FImage->IMinimum());
    }

    double SImage::ISourceYSquare()
    {
        return(FSource.y / FImage->IMinimum());
    }

    double SImage::ISourceWidthSquare()
    {
        return(FSource.w / FImage->IMinimum());
    }

    double SImage::ISourceHeightSquare()
    {
        return(FSource.h / FImage->IMinimum());
    }

    void SImage::ISourceXSquareAbsolute(double const& AX)
    {
        FSource.x = static_cast<std::int32_t>(std::round(FImage->IMinimum() * AX));
    }

    void SImage::ISourceYSquareAbsolute(double const& AY)
    {
        FSource.y = static_cast<std::int32_t>(std::round(FImage->IMinimum() * AY));
    }

    void SImage::ISourceWidthSquareAbsolute(double const& AWidth)
    {
        FSource.w = static_cast<std::int32_t>(std::round(FImage->IMinimum() * AWidth));
    }

    void SImage::ISourceHeightSquareAbsolute(double const& AHeight)
    {
        FSource.h = static_cast<std::int32_t>(std::round(FImage->IMinimum() * AHeight));
    }

    void SImage::ISourceXSquareRelative(double const& AX)
    {
        FSource.x += static_cast<std::int32_t>(std::round(FImage->IMinimum() * AX));
    }

    void SImage::ISourceYSquareRelative(double const& AY)
    {
        FSource.y += static_cast<std::int32_t>(std::round(FImage->IMinimum() * AY));
    }

    void SImage::ISourceWidthSquareRelative(double const& AWidth)
    {
        FSource.w += static_cast<std::int32_t>(std::round(FImage->IMinimum() * AWidth));
    }
    void SImage::ISourceHeightSquareRelative(double const& AHeight)
    {
        FSource.h += static_cast<std::int32_t>(std::round(FImage->IMinimum() * AHeight));
    }

    double SImage::IDestinationX()
    {
        return(FDestination.x);
    }

    double SImage::IDestinationY()
    {
        return(FDestination.y);
    }

    double SImage::IDestinationWidth()
    {
        return(FDestination.w);
    }

    double SImage::IDestinationHeight()
    {
        return(FDestination.h);
    }

    void SImage::IDestinationXAbsolute(double const& AX)
    {
        FDestination.x = static_cast<std::int32_t>(std::round(AX));
    }

    void SImage::IDestinationYAbsolute(double const& AY)
    {
        FDestination.y = static_cast<std::int32_t>(std::round(AY));
    }

    void SImage::IDestinationWidthAbsolute(double const& AWidth)
    {
        FDestination.w = static_cast<std::int32_t>(std::round(AWidth));
    }

    void SImage::IDestinationHeightAbsolute(double const& AHeight)
    {
        FDestination.h = static_cast<std::int32_t>(std::round(AHeight));
    }

    void SImage::IDestinationXRelative(double const& AX)
    {
        FDestination.x += static_cast<std::int32_t>(std::round(AX));
    }

    void SImage::IDestinationYRelative(double const& AY)
    {
        FDestination.y += static_cast<std::int32_t>(std::round(AY));
    }

    void SImage::IDestinationWidthRelative(double const& AWidth)
    {
        FDestination.w += static_cast<std::int32_t>(std::round(AWidth));
    }

    void SImage::IDestinationHeightRelative(double const& AHeight)
    {
        FDestination.h += static_cast<std::int32_t>(std::round(AHeight));
    }

    double SImage::IDestinationXRectangle()
    {
        return(GVideo.IPixelToRectangleHorizontal(FDestination.x));
    }

    double SImage::IDestinationYRectangle()
    {
        return(GVideo.IPixelToRectangleVertical(FDestination.y));
    }

    double SImage::IDestinationWidthRectangle()
    {
        return(GVideo.IPixelToRectangleHorizontal(FDestination.w));
    }

    double SImage::IDestinationHeightRectangle()
    {
        return(GVideo.IPixelToRectangleVertical(FDestination.h));
    }

    void SImage::IDestinationXRectangleAbsolute(double const& AX)
    {
        FDestination.x = static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelHorizontal(AX)));
    }

    void SImage::IDestinationYRectangleAbsolute(double const& AY)
    {
        FDestination.y = static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelVertical(AY)));
    }

    void SImage::IDestinationWidthRectangleAbsolute(double const& AWidth)
    {
        FDestination.w = static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelHorizontal(AWidth)));
    }

    void SImage::IDestinationHeightRectangleAbsolute(double const& AHeight)
    {
        FDestination.h = static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelVertical(AHeight)));
    }

    void SImage::IDestinationXRectangleRelative(double const& AX)
    {
        FDestination.x += static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelHorizontal(AX)));
    }

    void SImage::IDestinationYRectangleRelative(double const& AY)
    {
        FDestination.y += static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelVertical(AY)));
    }

    void SImage::IDestinationWidthRectangleRelative(double const& AWidth)
    {
        FDestination.w += static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelHorizontal(AWidth)));
    }

    void SImage::IDestinationHeightRectangleRelative(double const& AHeight)
    {
        FDestination.h += static_cast<std::int32_t>(std::round(GVideo.IRectangleToPixelVertical(AHeight)));
    }

    double SImage::IDestinationXSquare()
    {
        return(GVideo.IPixelToSquare(FDestination.x));
    }

    double SImage::IDestinationYSquare()
    {
        return(GVideo.IPixelToSquare(FDestination.y));
    }

    double SImage::IDestinationWidthSquare()
    {
        return(GVideo.IPixelToSquare(FDestination.w));
    }

    double SImage::IDestinationHeightSquare()
    {
        return(GVideo.IPixelToSquare(FDestination.h));
    }

    void SImage::IDestinationXSquareAbsolute(double const& AX)
    {
        FDestination.x = static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AX)));
    }

    void SImage::IDestinationYSquareAbsolute(double const& AY)
    {
        FDestination.y = static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AY)));
    }

    void SImage::IDestinationWidthSquareAbsolute(double const& AWidth)
    {
        FDestination.w = static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AWidth)));
    }

    void SImage::IDestinationHeightSquareAbsolute(double const& AHeight)
    {
        FDestination.h = static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AHeight)));
    }

    void SImage::IDestinationXSquareRelative(double const& AX)
    {
        FDestination.x += static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AX)));
    }

    void SImage::IDestinationYSquareRelative(double const& AY)
    {
        FDestination.y += static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AY)));
    }

    void SImage::IDestinationWidthSquareRelative(double const& AWidth)
    {
        FDestination.w += static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AWidth)));
    }

    void SImage::IDestinationHeightSquareRelative(double const& AHeight)
    {
        FDestination.h += static_cast<std::int32_t>(std::round(GVideo.ISquareToPixel(AHeight)));
    }

    void SImage::IDraw()
    {
        SDL_RenderCopy(GVideo.FRenderer , FImage->FHandle , &FSource , &FDestination);
    }
}
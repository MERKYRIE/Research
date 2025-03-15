#pragma once

namespace NResearch::NResearch::NSpace5
{
    //Naive image implementation
    
    struct SImage
    {
        //Contains image as loadable resource
        
        NVideo5::SImage* FImage;

        //Contains area to copy from

        SDL_Rect FSource;

        //Contains area to draw to

        SDL_Rect FDestination;

        //Configures empty image and areas

        SImage();

        //Configures image and adjusts areas

        void ILoad(NVideo5::SImage* const& AImage);
        void IUnload();

        //Configures source by different coordinates

        double ISourceX();
        double ISourceY();
        double ISourceWidth();
        double ISourceHeight();
        void ISourceXAbsolute(double const& AX);
        void ISourceYAbsolute(double const& AY);
        void ISourceWidthAbsolute(double const& AWidth);
        void ISourceHeightAbsolute(double const& AHeight);
        void ISourceXRelative(double const& AX);
        void ISourceYRelative(double const& AY);
        void ISourceWidthRelative(double const& AWidth);
        void ISourceHeightRelative(double const& AHeight);
        double ISourceXRectangle();
        double ISourceYRectangle();
        double ISourceWidthRectangle();
        double ISourceHeightRectangle();
        void ISourceXRectangleAbsolute(double const& AX);
        void ISourceYRectangleAbsolute(double const& AY);
        void ISourceWidthRectangleAbsolute(double const& AWidth);
        void ISourceHeightRectangleAbsolute(double const& AHeight);
        void ISourceXRectangleRelative(double const& AX);
        void ISourceYRectangleRelative(double const& AY);
        void ISourceWidthRectangleRelative(double const& AWidth);
        void ISourceHeightRectangleRelative(double const& AHeight);
        double ISourceXSquare();
        double ISourceYSquare();
        double ISourceWidthSquare();
        double ISourceHeightSquare();
        void ISourceXSquareAbsolute(double const& AX);
        void ISourceYSquareAbsolute(double const& AY);
        void ISourceWidthSquareAbsolute(double const& AWidth);
        void ISourceHeightSquareAbsolute(double const& AHeight);
        void ISourceXSquareRelative(double const& AX);
        void ISourceYSquareRelative(double const& AY);
        void ISourceWidthSquareRelative(double const& AWidth);
        void ISourceHeightSquareRelative(double const& AHeight);

        //Configures destination by different coordinates

        double IDestinationX();
        double IDestinationY();
        double IDestinationWidth();
        double IDestinationHeight();
        void IDestinationXAbsolute(double const& AX);
        void IDestinationYAbsolute(double const& AY);
        void IDestinationWidthAbsolute(double const& AWidth);
        void IDestinationHeightAbsolute(double const& AHeight);
        void IDestinationXRelative(double const& AX);
        void IDestinationYRelative(double const& AY);
        void IDestinationWidthRelative(double const& AWidth);
        void IDestinationHeightRelative(double const& AHeight);
        double IDestinationXRectangle();
        double IDestinationYRectangle();
        double IDestinationWidthRectangle();
        double IDestinationHeightRectangle();
        void IDestinationXRectangleAbsolute(double const& AX);
        void IDestinationYRectangleAbsolute(double const& AY);
        void IDestinationWidthRectangleAbsolute(double const& AWidth);
        void IDestinationHeightRectangleAbsolute(double const& AHeight);
        void IDestinationXRectangleRelative(double const& AX);
        void IDestinationYRectangleRelative(double const& AY);
        void IDestinationWidthRectangleRelative(double const& AWidth);
        void IDestinationHeightRectangleRelative(double const& AHeight);
        double IDestinationXSquare();
        double IDestinationYSquare();
        double IDestinationWidthSquare();
        double IDestinationHeightSquare();
        void IDestinationXSquareAbsolute(double const& AX);
        void IDestinationYSquareAbsolute(double const& AY);
        void IDestinationWidthSquareAbsolute(double const& AWidth);
        void IDestinationHeightSquareAbsolute(double const& AHeight);
        void IDestinationXSquareRelative(double const& AX);
        void IDestinationYSquareRelative(double const& AY);
        void IDestinationWidthSquareRelative(double const& AWidth);
        void IDestinationHeightSquareRelative(double const& AHeight);

        //Draws using image and areas

        void IDraw();
    };
}
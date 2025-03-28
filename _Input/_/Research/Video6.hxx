#pragma once

namespace NResearch::NResearch
{
    //Naive video implementation

    struct SVideo6
    {
        //Contains SDL-based functionalities for drawing
        
        SDL_Window* FWindow;
        SDL_Renderer* FRenderer;

        //Contains currently using window demensions

        double FWidth;
        double FHeight;

        //Contains window demensions respective limits

        double FMinimum;
        double FMaximum;

        //Contains window ratios for adjusting

        double FRatio;
        double FRatioInversed;

        //Contains all the fonts loaded

        std::unordered_map<std::string , std::shared_ptr<NVideo6::SFont>> FFonts;

        //Configures window, renderer and fonts

        SVideo6();

        //Clear and updates the window

        void IUpdate();

        //Returns a font by name

        NVideo6::SFont* IFont(std::string const& APath);

        //Converts different kinds of coordinates

        double IPixelToRectangleHorizontal(double const& APixel);
        double IPixelToRectangleVertical(double const& APixel);
        double IPixelToSquare(double const& APixel);
        double IRectangleToPixelHorizontal(double const& ARectangle);
        double IRectangleToPixelVertical(double const& ARectangle);
        double IRectangleToSquareHorizontal(double const& ARectangle);
        double IRectangleToSquareVertical(double const& ARectangle);
        double ISquareToPixel(double const& ASquare);
        double ISquareToRectangleHorizontal(double const& ASquare);
        double ISquareToRectangleVertical(double const& ASquare);

        //Terminates SDL-based functionalities for drawing 

        ~SVideo6();
    };
}
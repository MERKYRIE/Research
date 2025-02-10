#pragma once

namespace NResearch::NResearch
{
    inline struct SVideo
    {
        SDL_Window* FWindow;
        SDL_Renderer* FRenderer;
        double FWidth;
        double FHeight;
        double FMinimum;
        double FMaximum;
        double FRatio;
        double FRatioInversed;
        std::unordered_map<std::string , std::shared_ptr<NVideo::SFont>> FFonts;
        std::unordered_map<std::string , NVideo::SImage> FImages;

        SVideo();
        void IUpdate();
        NVideo::SFont* IFont(std::string const& APath);
        NVideo::SImage& IImage(std::string const& APath);
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
        ~SVideo();
    }
    GVideo;
}
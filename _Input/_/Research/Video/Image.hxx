#pragma once

namespace NResearch::NResearch::NVideo
{
    struct SImage
    {
        SDL_Texture* FHandle;

        SImage(std::string const& APath);
        SImage(TTF_Font* const& AFont , std::string const& AString);
        double IWidth();
        double IHeight();
        double IMinimum();
        double IMaximum();
        void IDraw(SDL_Rect const& ASource , SDL_Rect const& ADestination);
        ~SImage();
    };
}
#pragma once

namespace NResearch::NResearch::NVideo1
{
    //Naive image implementation
    
    struct SImage
    {
        //Contains image data virtual address
        
        SDL_Texture* FHandle;

        //Configures image from a font

        SImage(TTF_Font* const& AFont , std::string const& AString);

        //Returns image dimensions as reals

        double IWidth();
        double IHeight();

        //Returns image dimensions respective limits

        double IMinimum();
        double IMaximum();

        //Terminates SDL GPU-based data linkage

        ~SImage();
    };
}
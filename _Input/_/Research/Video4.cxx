#include"Research.hxx"

namespace NResearch::NResearch
{
    SVideo4::SVideo4()
    {
        GDebug.IHandle(FWindow = SDL_CreateWindow("Research" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP));
        GDebug.IHandle(FRenderer = SDL_CreateRenderer(FWindow , -1 , SDL_RENDERER_ACCELERATED));
        SDL_DisplayMode LDisplayMode;
        GDebug.ICode(SDL_GetWindowDisplayMode(FWindow , &LDisplayMode));
        FWidth = LDisplayMode.w;
        FHeight = LDisplayMode.h;
        FMinimum = std::min(FWidth , FHeight);
        FMaximum = std::max(FWidth , FHeight);
        FRatio = static_cast<double>(FWidth) / static_cast<double>(FHeight);
        FRatioInversed = static_cast<double>(FHeight) / static_cast<double>(FWidth);
        GDebug.ICode(TTF_Init());
        for(std::filesystem::directory_entry const& LEntry : std::filesystem::recursive_directory_iterator{"Fonts"})
        {
            if(LEntry.path().extension() == ".ttf")
            {
                FFonts.emplace(LEntry.path().generic_string().substr(LEntry.path().generic_string().find('/')) , std::make_shared<NVideo4::SFont>(LEntry.path().generic_string()));
            }
        }
    }

    void SVideo4::IUpdate()
    {
        SDL_RenderPresent(FRenderer);
        SDL_RenderClear(FRenderer);
    }

    NVideo4::SFont* SVideo4::IFont(std::string const& APath)
    {
        return(std::ranges::find_if(FFonts , [&](auto const& AFont)->bool{return(AFont.first == APath);})->second.get());
    }

    double SVideo4::IPixelToRectangleHorizontal(double const& APixel)
    {
        return(APixel / FWidth);
    }

    double SVideo4::IPixelToRectangleVertical(double const& APixel)
    {
        return(APixel / FHeight);
    }

    double SVideo4::IPixelToSquare(double const& APixel)
    {
        return(APixel / FMinimum);
    }

    double SVideo4::IRectangleToPixelHorizontal(double const& ARectangle)
    {
        return(FWidth * ARectangle);
    }

    double SVideo4::IRectangleToPixelVertical(double const& ARectangle)
    {
        return(FHeight * ARectangle);
    }

    double SVideo4::IRectangleToSquareHorizontal(double const& ARectangle)
    {
        return(IPixelToSquare(IRectangleToPixelHorizontal(ARectangle)));
    }

    double SVideo4::IRectangleToSquareVertical(double const& ARectangle)
    {
        return(IPixelToSquare(IRectangleToPixelVertical(ARectangle)));
    }

    double SVideo4::ISquareToPixel(double const& ASquare)
    {
        return(FMinimum * ASquare);
    }

    double SVideo4::ISquareToRectangleHorizontal(double const& ASquare)
    {
        return(IPixelToRectangleHorizontal(ISquareToPixel(ASquare)));
    }

    double SVideo4::ISquareToRectangleVertical(double const& ASquare)
    {
        return(IPixelToRectangleVertical(ISquareToPixel(ASquare)));
    }

    SVideo4::~SVideo4()
    {
        FFonts.clear();
        TTF_Quit();
        SDL_DestroyRenderer(FRenderer);
        SDL_DestroyWindow(FWindow);
    }
}
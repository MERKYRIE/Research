#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2main")
#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2")
#pragma comment(lib , "../SimpleDirectMediaLayer/TrueTypeFont/SDL2_ttf")

#include"Research.hxx"

namespace NResearch
{
    SResearch::SResearch()
    {
        NResearch::GDebug.ICode(SDL_Init(SDL_INIT_EVERYTHING));
    }
    
    void SResearch::IInitiate()
    {
        while(NResearch::GKeyboard.FKeys["Escape"]->FState == "Up")
        {
            NResearch::GKeyboard.IUpdate();
            NResearch::GMouse.IUpdate();
            NResearch::GTime.IUpdate();
            NResearch::GSpace.IUpdate();
            NResearch::GVideo.IUpdate();
        };
    }

    SResearch::~SResearch()
    {
        SDL_Quit();
    }
}

std::int32_t main(std::int32_t , char**)
{
    NResearch::GResearch.IInitiate();
    return(0);
}
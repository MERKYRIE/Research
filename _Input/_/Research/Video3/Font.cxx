#include"Research.hxx"

namespace NResearch::NResearch::NVideo3
{
    SFont::SFont(std::string const& APath)
    {
        TTF_Font* LFont{TTF_OpenFont(APath.c_str() , 64)};
        GDebug.IHandle(LFont);
        for(char LDigit{'0'} ; LDigit <= '9' ; LDigit++)
        {
            FDigits.emplace_back(std::make_shared<SImage>(LFont , std::string{LDigit}));
        }
        FDigits.shrink_to_fit();
        for(char LUppercase{'A'} ; LUppercase <= 'Z' ; LUppercase++)
        {
            FUppercases.emplace_back(std::make_shared<SImage>(LFont , std::string{LUppercase}));
        }
        FUppercases.shrink_to_fit();
        for(char LLowercase{'a'} ; LLowercase <= 'z' ; LLowercase++)
        {
            FLowercases.emplace_back(std::make_shared<SImage>(LFont , std::string{LLowercase}));
        }
        FLowercases.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Strings"})
        {
            if(LEntry.path().extension() == ".txt")
            {
                std::fstream LStream{LEntry.path().string() , std::ios::in};
                while(LStream)
                {
                    std::string LString;
                    LStream >> LString;
                    if(LStream)
                    {
                        FStrings.emplace(LString , std::make_shared<SImage>(LFont , LString));
                    }
                }
            }
        }
        TTF_CloseFont(LFont);
    }

    SImage* SFont::IDigit(char const& ACode)
    {
        return(FDigits[static_cast<std::int64_t>(ACode) - static_cast<std::int64_t>('0')].get());
    }

    SImage* SFont::IUppercase(char const& ACode)
    {
        return(FUppercases[static_cast<std::int64_t>(ACode) - static_cast<std::int64_t>('A')].get());
    }

    SImage* SFont::ILowercase(char const& ACode)
    {
        return(FLowercases[static_cast<std::int64_t>(ACode) - static_cast<std::int64_t>('a')].get());
    }

    SImage* SFont::IString(std::string const& AString)
    {
        return(std::ranges::find_if(FStrings , [&](auto const& AImage)->bool{return(AImage.first == AString);})->second.get());
    }

    SFont::~SFont()
    {
        FLowercases.clear();
        FUppercases.clear();
        FDigits.clear();
    }
}
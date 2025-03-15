#pragma once

namespace NResearch::NResearch::NVideo6
{
    //Naive font implementation
    
    struct SFont
    {       
        //Contains different characters by category
        
        std::vector<std::shared_ptr<SImage>> FDigits;
        std::vector<std::shared_ptr<SImage>> FUppercases;
        std::vector<std::shared_ptr<SImage>> FLowercases;

        //Contains loaded strings as images

        std::unordered_map<std::string , std::shared_ptr<SImage>> FStrings;

        //Configures images from loaded strings

        SFont(std::string const& APath);

        //Returns different character by category

        SImage* IDigit(char const& ACode);
        SImage* IUppercase(char const& ACode);
        SImage* ILowercase(char const& ACode);

        //Return loaded string as image

        SImage* IString(std::string const& AString);

        //Terminates images from loaded strings

        ~SFont();
    };
}
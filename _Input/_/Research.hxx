#pragma once

#include<array>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<numbers>
#include<random>
#include<source_location>
#include<string>
#include<unordered_map>
#include<variant>
#include<vector>

#pragma warning(push)
    #pragma warning(disable : 26819)

    #include"../SimpleDirectMediaLayer/SDL.h"
    #include"../SimpleDirectMediaLayer/Image/SDL_image.h"
    #include"../SimpleDirectMediaLayer/Mixer/SDL_mixer.h"
    #include"../SimpleDirectMediaLayer/TrueTypeFont/SDL_ttf.h"
#pragma warning(pop)

#pragma warning(disable : 26495)

namespace NResearch
{
    inline struct SResearch
    {
        SResearch();
        void IInitiate();
        ~SResearch();
    }
    GResearch;

    namespace NResearch
    {
        namespace NAudio
        {
            struct SSound;
            struct STrack;
        }
        
        namespace NKeyboard
        {
            struct SKey;
        }
            
        namespace NMouse
        {
            struct SAbsolute;
            struct SButton;
            struct SCursor;
            struct SPixel;
            struct SRectangle;
            struct SRelative;
            struct SSquare;
            struct SWheel;
        }

        namespace NSpace
        {
            struct SEntity;
            struct SImage;
            struct SPartition;
            struct STerrain;
        }

        namespace NVideo
        {
            struct SFont;
            struct SImage;
        }
    }
}

#include"Research/Audio/Sound.hxx"
#include"Research/Audio/Track.hxx"
#include"Research/Keyboard/Key.hxx"
#include"Research/Mouse/Absolute.hxx"
#include"Research/Mouse/Button.hxx"
#include"Research/Mouse/Cursor.hxx"
#include"Research/Mouse/Pixel.hxx"
#include"Research/Mouse/Rectangle.hxx"
#include"Research/Mouse/Relative.hxx"
#include"Research/Mouse/Square.hxx"
#include"Research/Mouse/Wheel.hxx"
#include"Research/Space/Entity.hxx"
#include"Research/Space/Image.hxx"
#include"Research/Space/Partition.hxx"
#include"Research/Space/Terrain.hxx"
#include"Research/Video/Font.hxx"
#include"Research/Video/Image.hxx"

#include"Research/Debug.hxx"
#include"Research/Audio.hxx"
#include"Research/Keyboard.hxx"
#include"Research/Mouse.hxx"
#include"Research/Time.hxx"
#include"Research/Video.hxx"
#include"Research/Space.hxx"
#include"Research/Interface.hxx"
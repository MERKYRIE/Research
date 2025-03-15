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

        namespace NSpace1
        {
            struct SEntity;
            struct SGround;
            struct SImage;
            struct SPartition;
        }

        namespace NSpace2
        {
            struct SEntity;
            struct SGround;
            struct SImage;
            struct SPartition;
        }

        namespace NSpace3
        {
            struct SEntity;
            struct SGround;
            struct SImage;
            struct SPartition;
        }

        namespace NVideo1
        {
            struct SFont;
            struct SImage;
        }

        namespace NVideo2
        {
            struct SFont;
            struct SImage;
        }

        namespace NVideo3
        {
            struct SFont;
            struct SImage;
        }
    }
}

#include"Research/Keyboard/Key.hxx"
#include"Research/Mouse/Absolute.hxx"
#include"Research/Mouse/Button.hxx"
#include"Research/Mouse/Cursor.hxx"
#include"Research/Mouse/Pixel.hxx"
#include"Research/Mouse/Rectangle.hxx"
#include"Research/Mouse/Relative.hxx"
#include"Research/Mouse/Square.hxx"
#include"Research/Mouse/Wheel.hxx"
#include"Research/Space1/Entity.hxx"
#include"Research/Space1/Ground.hxx"
#include"Research/Space1/Image.hxx"
#include"Research/Space1/Partition.hxx"
#include"Research/Space2/Entity.hxx"
#include"Research/Space2/Ground.hxx"
#include"Research/Space2/Image.hxx"
#include"Research/Space2/Partition.hxx"
#include"Research/Space3/Entity.hxx"
#include"Research/Space3/Ground.hxx"
#include"Research/Space3/Image.hxx"
#include"Research/Space3/Partition.hxx"
#include"Research/Video1/Font.hxx"
#include"Research/Video1/Image.hxx"
#include"Research/Video2/Font.hxx"
#include"Research/Video2/Image.hxx"
#include"Research/Video3/Font.hxx"
#include"Research/Video3/Image.hxx"

#include"Research/Debug.hxx"
#include"Research/Keyboard.hxx"
#include"Research/Mouse.hxx"
#include"Research/Time.hxx"
#include"Research/Video1.hxx"
#include"Research/Video2.hxx"
#include"Research/Video3.hxx"
#include"Research/Space1.hxx"
#include"Research/Space2.hxx"
#include"Research/Space3.hxx"
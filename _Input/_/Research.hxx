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

        namespace NSpace4
        {
            struct SEntity;
            struct SGround;
            struct SImage;
            struct SPartition;
        }

        namespace NSpace5
        {
            struct SEntity;
            struct SGround;
            struct SImage;
        }

        namespace NSpace6
        {
            struct SEntity;
            struct SGround;
            struct SImage;
        }

        namespace NSpace7
        {
            struct SEntity;
            struct SGround;
            struct SImage;
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

        namespace NVideo4
        {
            struct SFont;
            struct SImage;
        }

        namespace NVideo5
        {
            struct SFont;
            struct SImage;
        }

        namespace NVideo6
        {
            struct SFont;
            struct SImage;
        }

        namespace NVideo7
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
#include"Research/Space4/Entity.hxx"
#include"Research/Space4/Ground.hxx"
#include"Research/Space4/Image.hxx"
#include"Research/Space4/Partition.hxx"
#include"Research/Space5/Entity.hxx"
#include"Research/Space5/Ground.hxx"
#include"Research/Space5/Image.hxx"
#include"Research/Space6/Entity.hxx"
#include"Research/Space6/Ground.hxx"
#include"Research/Space6/Image.hxx"
#include"Research/Space7/Entity.hxx"
#include"Research/Space7/Ground.hxx"
#include"Research/Space7/Image.hxx"
#include"Research/Video1/Font.hxx"
#include"Research/Video1/Image.hxx"
#include"Research/Video2/Font.hxx"
#include"Research/Video2/Image.hxx"
#include"Research/Video3/Font.hxx"
#include"Research/Video3/Image.hxx"
#include"Research/Video4/Font.hxx"
#include"Research/Video4/Image.hxx"
#include"Research/Video5/Font.hxx"
#include"Research/Video5/Image.hxx"
#include"Research/Video6/Font.hxx"
#include"Research/Video6/Image.hxx"
#include"Research/Video7/Font.hxx"
#include"Research/Video7/Image.hxx"

#include"Research/Debug.hxx"
#include"Research/Keyboard.hxx"
#include"Research/Mouse.hxx"
#include"Research/Time.hxx"
#include"Research/Video1.hxx"
#include"Research/Video2.hxx"
#include"Research/Video3.hxx"
#include"Research/Video4.hxx"
#include"Research/Video5.hxx"
#include"Research/Video6.hxx"
#include"Research/Video7.hxx"
#include"Research/Space1.hxx"
#include"Research/Space2.hxx"
#include"Research/Space3.hxx"
#include"Research/Space4.hxx"
#include"Research/Space5.hxx"
#include"Research/Space6.hxx"
#include"Research/Space7.hxx"
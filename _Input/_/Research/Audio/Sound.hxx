#pragma once

namespace NResearch::NResearch::NAudio
{
    struct SSound
    {
        std::string FPath;
        Mix_Chunk* FHandle;
        std::int64_t FChannel;

        SSound(std::string const& APath);
        void IPlay();
        bool IState();
        ~SSound();
    };
}
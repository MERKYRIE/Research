#pragma once

namespace NResearch::NResearch::NAudio
{
    struct STrack
    {
        std::string FPath;
        Mix_Music* FHandle;

        STrack(std::string const& APath);
        void IPlay();
        void IPause();
        void IResume();
        void IStop();
        void IVolume(std::int64_t const& ALevel);
        ~STrack();
    };
}
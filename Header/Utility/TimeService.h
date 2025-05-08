#pragma once
#include <chrono>

namespace Utility
{
    class TimeService
    {
    private:
        std::chrono::steady_clock::time_point previous_time;//represents a point in time from steadyclock
        float delta_time;

        //functions for calculating and updating delta time and lifecycle functions.
        void updateDeltaTime();
        float calculateDeltaTime();
        void updatePreviousTime();//update prev time to current time

    public:
        void initialize();
        void update();
        float getDeltaTime();
    };
}
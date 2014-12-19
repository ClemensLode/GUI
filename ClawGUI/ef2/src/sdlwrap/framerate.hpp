#ifndef _SDL_FRAMERATE_HPP
#define _SDL_FRAMERATE_HPP

#pragma warning(push, 0)  
#include <SDL.h>
#pragma warning(pop)

#include "export.hpp"
#define FPS_AVERAGE_VALUES 100

#include <list>
#include "enums/frameticks.hpp"

#define TICK_INTERVALL 2


class SDL_API FrameRate
{
	public:
		
		bool allowCalculation();

		const std::list<unsigned int> getPercentList() const;
		double getFramesPerSecond() const;
		unsigned int getGenerationsPerSecond() const;		


		FrameRate(const unsigned int desired_framerate, const unsigned int desired_cpu);
		~FrameRate();

		bool setDesiredFramerate(const unsigned int desired_frame_rate);
		bool setDesiredCPU(const unsigned int desired_cpu_usage);
		void setTotalTicks(const long unsigned int total_ticks);
		void setAdaptFramesPerGeneration(const bool adapt);
		unsigned int getFramesPerGeneration() const;
		double getCurrentFramerate() const;
    	void delay();
		void poll(const eFrameTicks eframetick);

	private:
		static const unsigned int FPS_UPPER_LIMIT;
		static const unsigned int FPS_LOWER_LIMIT;
		static const unsigned int FPS_DEFAULT;
		static const unsigned int FPS_MAX_TOTAL_TICKS;
		static const unsigned int FPS_MIN_TOTAL_TICKS;

		void calculateFramerate();

		unsigned int desiredFramerate;
		double currentFramerate;
		unsigned int desiredCPU;
		unsigned int framesPerGeneration; // output

		unsigned int framecount;
		
		double rateTicks;
		
		long unsigned int startTicks;
		long unsigned int lastTicks;
		long unsigned int totalTicks;

		long unsigned int delayTicks;

		bool adaptFramesPerGeneration;

		unsigned int refresh;
		
		unsigned int averagecounter;
		unsigned int average[FPS_AVERAGE_VALUES];

		long unsigned int currentTicks;
		long unsigned int ticks[MAX_TICK_TYPES][TICK_INTERVALL];
		double frames_count[TICK_INTERVALL];
		double framesPerSecond;
		unsigned int generationsPerSecond;
		unsigned int percent[MAX_TICK_TYPES];

		unsigned int tickIntervall;
};

inline void FrameRate::setAdaptFramesPerGeneration(const bool adapt) {
	adaptFramesPerGeneration = adapt;
}

inline unsigned int FrameRate::getFramesPerGeneration() const {
	return framesPerGeneration;
}

inline double FrameRate::getCurrentFramerate() const {
	return currentFramerate;
}

inline double FrameRate::getFramesPerSecond() const {
	return framesPerSecond;
}

inline unsigned int FrameRate::getGenerationsPerSecond() const {
	return generationsPerSecond;
}


#endif	// _SDL_FRAMERATE_HPP


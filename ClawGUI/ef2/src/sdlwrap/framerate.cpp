#include "framerate.hpp"
#include <iostream>
#include <sstream>

#include <misc/exceptions.hpp>

#pragma warning(push, 0)  
#include <boost/assert.hpp>
#pragma warning(pop)


FrameRate::FrameRate(const unsigned int desired_framerate, const unsigned int desired_cpu):
	desiredFramerate(FPS_DEFAULT),
	currentFramerate(FPS_DEFAULT),
	desiredCPU(100),
	framesPerGeneration(100),
	framecount(0),
	rateTicks(1000.0 / FPS_DEFAULT),
	startTicks(SDL_GetTicks()),
	lastTicks(SDL_GetTicks()),
	totalTicks(400),
	delayTicks(100),
	adaptFramesPerGeneration(true),
	refresh(0),
	averagecounter(0),
	currentTicks(0), // has to be zero here
	framesPerSecond(10),
	generationsPerSecond(0),
	tickIntervall(0)
	
{
	for(unsigned int i = FPS_AVERAGE_VALUES; i--;) {
		average[i] = 20;
	}

	for(unsigned int i = MAX_TICK_TYPES;i--;) {
		for(unsigned int j = TICK_INTERVALL;j--;) {
			ticks[i][j] = 0;
		}
	}
	for(unsigned int j = TICK_INTERVALL;j--;) {
		frames_count[j] = 0.0;
	}
	for(unsigned int i = MAX_TICK_TYPES; i--;) {
		percent[i] = 0;
	}

	setDesiredCPU(desired_cpu);
	setDesiredFramerate(desired_framerate);
}


FrameRate::~FrameRate()
{ }

void FrameRate::setTotalTicks(const long unsigned int total_ticks) 
{
#ifdef _SCC_DEBUG
	if(total_ticks > FPS_MAX_TOTAL_TICKS || total_ticks < FPS_MIN_TOTAL_TICKS) {
		throw SDLException("WARNING (FrameRate::setTotalTicks()): Exceptional short or long delay, total_ticks out of range.");
	}
#endif
	if(total_ticks > FPS_MAX_TOTAL_TICKS) {
		totalTicks = FPS_MAX_TOTAL_TICKS;
	} else if(total_ticks < FPS_MIN_TOTAL_TICKS) {
		totalTicks = FPS_MIN_TOTAL_TICKS;
	} else {
		totalTicks = total_ticks;
	}
}


bool FrameRate::setDesiredFramerate(const unsigned int desired_frame_rate)
{
	if(desiredFramerate == desired_frame_rate) {
		return false;
	}
#ifdef _SCC_DEBUG
	if(desired_frame_rate > FPS_UPPER_LIMIT || desired_frame_rate < FPS_LOWER_LIMIT) {
		throw SDLException("WARNING (FrameRate::setDesiredFramerate()): Desired Framerate usage value out of range.");
	}
#endif
	if(desired_frame_rate > FPS_UPPER_LIMIT) {
		desiredFramerate = FPS_UPPER_LIMIT;
	} else if(desired_frame_rate < FPS_LOWER_LIMIT) {
		desiredFramerate = FPS_LOWER_LIMIT;
	} else {
		desiredFramerate = desired_frame_rate;
	}

	framecount = 0;
	rateTicks = (1000.0 / desiredFramerate);

	return true;
}

bool FrameRate::setDesiredCPU(const unsigned int desired_cpu_usage)
{
	if(desiredCPU == desired_cpu_usage) {
		return false;
	}
#ifdef _SCC_DEBUG
	if((desired_cpu_usage<1)||(desired_cpu_usage>100)) {
		throw SDLException("WARNING (FrameRate::setDesiredCPU()): Desired CPU usage value out of range.");
	}
#endif

	if(desired_cpu_usage < 1) {
		desiredCPU = 1;
	} else if(desired_cpu_usage > 100) {
		desiredCPU = 100;
	} else {
		desiredCPU = desired_cpu_usage;
	}
	return true;
}


void FrameRate::poll(const eFrameTicks etick)
{
	ticks[etick][tickIntervall] = SDL_GetTicks() - currentTicks;
	currentTicks = SDL_GetTicks();
}

void FrameRate::calculateFramerate()
{
	tickIntervall++;
	if(tickIntervall >= TICK_INTERVALL) {
		tickIntervall = 0;
	}
	
	totalTicks = 0;
	unsigned int total_this_ticks[MAX_TICK_TYPES];
	for(unsigned int i = MAX_TICK_TYPES;i--;)
	{
		total_this_ticks[i]=0;
		for(unsigned int j = TICK_INTERVALL;j--;) {
			total_this_ticks[i] += ticks[i][j];
		}
		totalTicks+=total_this_ticks[i];
		
	}
	if(totalTicks == 0) {
		totalTicks = 1;
	}
	double total_frames = 0;
	for(unsigned int j = TICK_INTERVALL;j--;) {
		total_frames += frames_count[j];
	}
	total_frames /= static_cast<double>(TICK_INTERVALL);

	if(framesPerSecond > total_frames) {
		framesPerSecond -= (framesPerSecond - total_frames)/5.0 + 1.0;
	} else {
		if(framesPerSecond < total_frames) {
			framesPerSecond += (total_frames - framesPerSecond)/5.0 + 1.0;
		}
	}
		
	for(unsigned int i = MAX_TICK_TYPES; i--;)
	{
		if(percent[i] > total_this_ticks[i] * 100 / totalTicks) {
			percent[i] -= (percent[i] - total_this_ticks[i] * 100 / totalTicks)/5 + 1;
		} else {
			if(percent[i] < total_this_ticks[i] * 100 / totalTicks) {
				percent[i] += (total_this_ticks[i] * 100 / totalTicks - percent[i])/5 + 1;
			}
		}
		
		if(percent[i] > 100) {
			percent[i] = 100;
		}
	}
	
	framesPerSecond = 0.0;
	for(unsigned int j = TICK_INTERVALL;j--;) {
		framesPerSecond += frames_count[j];
	}
	framesPerSecond /= static_cast<double>(TICK_INTERVALL);
}

void FrameRate::delay()
{
	calculateFramerate();
	frames_count[tickIntervall] = currentFramerate;
	totalTicks = 1+totalTicks/TICK_INTERVALL;

// Increase/Reduce the frames per generation
	Uint32 currentTicks = SDL_GetTicks();
	long int difference = currentTicks - startTicks;
	if(difference < 0) {
		startTicks = SDL_GetTicks();
		difference = 1;
	} else /*if(difference == 0) {
		difference = 1;
		startTicks++;
	} else */ {
   		startTicks += difference;
	}

	if(averagecounter < 100) {
   		++averagecounter;
	}
	for(unsigned int i = averagecounter; i--;) {
   		average[i+1] = average[i];
	}
	average[0] = difference;
	long int av = 0;
	for(unsigned int i = averagecounter; i--;) {
   		av += average[i];
	}
	double value = 0.0001;
	if(av != 0) {
		value = av;
	}
	
	currentFramerate = 1000.0 * static_cast<double>(averagecounter) / value;
	long unsigned int cpu_delay = (totalTicks - desiredCPU * totalTicks / 100);

	if(adaptFramesPerGeneration)
	{
		if((currentFramerate > desiredFramerate) && (framesPerGeneration > 1))
			--framesPerGeneration;
		else 
		if((currentFramerate < desiredFramerate) && (framesPerGeneration < 1000)) //100?
			++framesPerGeneration;
	} else if(currentFramerate > desiredFramerate)
	{
        Uint32 current_ticks;
		Uint32 target_ticks;
        Uint32 the_delay = 0;

        framecount++;
        current_ticks = SDL_GetTicks();
        target_ticks = lastTicks + static_cast<Uint32>(framecount * rateTicks);

        if (current_ticks <= target_ticks) {
			the_delay = target_ticks - current_ticks;
			SDL_Delay(the_delay);
        } else {
			framecount = 0;
            lastTicks = SDL_GetTicks();
		}
	}
	if((delayTicks < cpu_delay) && (delayTicks < 1000)) {
		delayTicks += (cpu_delay - delayTicks)/5 + 1;
	}
	else if(delayTicks > cpu_delay) {
		delayTicks -= (delayTicks - cpu_delay)/2 + 1; // reduce delayTicks very fast because smooth drawing has priority over processor usage!
	}
	if(delayTicks > 1) {
		SDL_Delay(delayTicks);	
		std::cout << "Delay: " << delayTicks << std::endl;
	}
	refresh += 100;
}

bool FrameRate::allowCalculation()
{
	bool allow = (refresh >= framesPerGeneration);
	if(framesPerGeneration > refresh) {
		refresh = 0;
	} else {
		refresh -= framesPerGeneration;
	}
	generationsPerSecond++;
	return allow;
}


const std::list<unsigned int> FrameRate::getPercentList() const
{
	std::list<unsigned int> t;
	for(unsigned int i = 0; i < MAX_TICK_TYPES; i++) {
		t.push_back(percent[i]);
	}
	return t;
}






const unsigned int FrameRate::FPS_UPPER_LIMIT = 1000;
const unsigned int FrameRate::FPS_LOWER_LIMIT = 2;
const unsigned int FrameRate::FPS_DEFAULT = 30;
const unsigned int FrameRate::FPS_MAX_TOTAL_TICKS = 100000;
const unsigned int FrameRate::FPS_MIN_TOTAL_TICKS = 1;



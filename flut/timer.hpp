#pragma once

#if ( _MSC_VER <= 1800 ) // MSVC 2013 and lower do not have proper chrono support
#	define FLUT_USE_WINDOWS_PERFORMANCE_COUNTER
#	include <profileapi.h>
#else
#	include <chrono>
#endif

namespace flut
{
	class timer
	{
	public:
		/// constructor, resets timer
		timer() {
#			ifdef FLUT_USE_WINDOWS_PERFORMANCE_COUNTER
				LARGE_INTEGER freq;
				::QueryPerformanceFrequency( &freq );
				ticks_to_seconds = 1.0 / double( freq.QuadPart );
#			endif
			reset();
		}

		/// reset timer
		void reset() {
#			ifdef FLUT_USE_WINDOWS_PERFORMANCE_COUNTER
				::QueryPerformanceCounter( &epoch );
#			else
				epoch = std::chrono::high_resolution_clock::now();
#			endif
		}

		/// get elapsed time in seconds
		double seconds() {
#			ifdef FLUT_USE_WINDOWS_PERFORMANCE_COUNTER
				return ticks() * ticks_to_seconds;
#			else
				return std::chrono::duration< double >( std::chrono::high_resolution_clock::now() - epoch ).count();
#			endif
		}

		/// get elapsed number of CPU ticks
		long long ticks() {
#			ifdef FLUT_USE_WINDOWS_PERFORMANCE_COUNTER
				LARGE_INTEGER now;
				::QueryPerformanceCounter( &now );
				return now.QuadPart - epoch.QuadPart;
#			else
				return ( std::chrono::high_resolution_clock::now() - epoch ).count();
#			endif
		}

	private:
#		ifdef FLUT_USE_WINDOWS_PERFORMANCE_COUNTER
			LARGE_INTEGER epoch;
			double ticks_to_seconds;
#		else
			std::chrono::time_point< std::chrono::high_resolution_clock, std::chrono::high_resolution_clock::duration > epoch;
#		endif
	};
}

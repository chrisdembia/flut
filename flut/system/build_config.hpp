#pragma once

#ifndef FLUT_USE_EXCEPTIONS
	#define FLUT_USE_EXCEPTIONS 1
#endif

#if FLUT_USE_EXCEPTIONS
	#ifndef FLUT_USE_ASSERT
		#define FLUT_USE_ASSERT 1
	#endif
#endif

#ifndef FLUT_STATIC_LOG_LEVEL
	#define FLUT_STATIC_LOG_LEVEL FLUT_LOG_LEVEL_INFO
#endif

#ifndef FLUT_LOG_OUTPUT_STREAM
	#define FLUT_LOG_OUTPUT_STREAM std::cout
#endif

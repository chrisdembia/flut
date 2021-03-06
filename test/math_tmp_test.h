#pragma once

#include "flut/math/vec3.hpp"
#include "flut/math/quat_tmp.hpp"

using flut::math::vec3;
using flut::math::quat;
using flut::math::quatf;

namespace flut 
{
	namespace math
	{
		struct dbl4 {
			dbl4( double x, double y, double z, double w ) { data[ 0 ] = x; data[ 1 ] = y; data[ 2 ] = z; data[ 3 ] = w; }
			double data[ 4 ];
		};
		template<> struct v4i< dbl4 >
		{
			typedef double elem_t;
			static const elem_t& w( const dbl4& q ) { return q.data[ 3 ]; }
			static const elem_t& x( const dbl4& q ) { return q.data[ 0 ]; }
			static const elem_t& y( const dbl4& q ) { return q.data[ 1 ]; }
			static const elem_t& z( const dbl4& q ) { return q.data[ 2 ]; }
			static dbl4 make( elem_t w, elem_t x, elem_t y, elem_t z ) { return dbl4( x, y, z, w ); }
			const static bool value = true;
		};
	}
}

void math_tmp_test()
{
	auto v1 = vec3( 1, 2, 3 );
	auto v2 = vec3( 4, 5, 6 );
	auto v3 = v2 - v1;
	auto q1 = flut::math::make_from_axes< quat >( v1, v2, v3 );
	auto v4 = q1 * v1;
	quatf qf = flut::math::make_from_axes< quatf >( v1, v2, v3 );
	auto v5 = qf * v1;
	auto qda = flut::math::make_from_quat< dbl4 >( qf );
}

#ifndef _AUX_UTILS
#define _AUX_UTILS

#include <string>
#include <numeric>
#include <vector>
#include <windows.h>

/**
 * Auxiliary functions
 */
namespace LaserScanner
{
	float	mapValue( float val, float istart, float istop, float ostart, float ostop );

	/*
	 * @brief Stores values and returns the average of all of them
	 */
	struct	Average
	{
		Average()
		{
			nValues = 30;
			values.reserve( nValues );
			index = 0;
		}
		/// @param nValues number of values to store
		Average( int _nValues )
		{
			nValues = _nValues;
			values.reserve( nValues );
			index = 0;
		}

		/// @brief ads a value to average
		void addValue( double value )
		{
			if ( values.size() < nValues )
				values.push_back( value );
			else
				values[index] = value;

			// calculate new index
			index = (++index) % values.capacity();
		}

		/// @brief returns the average
		double getValue()
		{
			double sum = std::accumulate( values.begin(), values.end(), 0.0 );
			return sum / (double)values.size();
		}

		std::vector< double >	values;
		size_t					nValues;
		size_t					index;
	};
}

#endif
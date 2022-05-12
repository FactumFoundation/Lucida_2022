#include "AuxUtils.h"

namespace LaserScanner
{
	//------------------------------------------------------------------------------------------------------------------
	// mapValue()
	// Code from processing.org
	//------------------------------------------------------------------------------------------------------------------
	float mapValue( float val, float istart, float istop, float ostart, float ostop )
	{
		return ostart + (ostop - ostart) * ((val - istart) / (istop - istart));
	}
}
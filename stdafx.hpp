#ifndef STDAFX_HPP
#define STDAFX_HPP

#include "CTRPluginFramework.hpp"
#include "3ds.h"
#include "types.h"

#include <3ds.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <math.h>
#include <random>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

namespace CTRPluginFramework
{
	using namespace std;

	using CallbackPointer = void (*)(void);
	using OnInputChange = void(*)(Keyboard &keyboard, InputChangeEvent &event);
	using String = string;
	using StringVector = vector<string>;
	using uVector32 = vector<u32>;
	using uVector16 = vector<u16>;
	using uVector8 = vector<u8>;
	using sVector32 = vector<s32>;
	using sVector16 = vector<s16>;
	using sVector8 = vector<s8>;

	static vu32 (*PointerFunction)(),
	            (*PointerFunction1)(u32 Parameter1),
                (*PointerFunction2)(u32 Parameter1, u32 Parameter2),
                (*PointerFunction3)(u32 Parameter1, u32 Parameter2, u32 Parameter3),
                (*PointerFunction4)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4),
                (*PointerFunction5)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5),
                (*PointerFunction6)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5, u32 Parameter6),
                (*PointerFunction7)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5, u32 Parameter6, u32 Parameter7),
                (*PointerFunction8)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5, u32 Parameter6, u32 Parameter7, u32 Parameter8),
                (*PointerFunction9)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5, u32 Parameter6, u32 Parameter7, u32 Parameter8, u32 Parameter9),
                (*PointerFunction10)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5, u32 Parameter6, u32 Parameter7, u32 Parameter8, u32 Parameter9, u32 Parameter10),
                (*PointerFunction11)(u32 Parameter1, u32 Parameter2, u32 Parameter3, u32 Parameter4, u32 Parameter5, u32 Parameter6, u32 Parameter7, u32 Parameter8, u32 Parameter9, u32 Parameter10, u32 Parameter11);
}

#endif

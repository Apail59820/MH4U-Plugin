#include "Convert.hpp"

namespace CTRPluginFramework
{
	String Convert::Hexadecimal(u8 Value)
	{
		char Buffer[3];

		sprintf(Buffer, "%01X", Value);
		return (String(Buffer));
	}

	String Convert::Hexadecimal(u16 Value)
	{
		char Buffer[5];

		sprintf(Buffer, "%01X", Value);
		return (String(Buffer));
	}

	String Convert::Hexadecimal(u32 Value)
	{
		char Buffer[9];

		sprintf(Buffer, "%01X", Value);
		return (String(Buffer));
	}

	String Convert::Hexadecimal(u64 Value)
	{
		char Buffer[17];

		sprintf(Buffer, "%01X", Value);
		return (String(Buffer));
	}

	String Convert::Decimal(u8 Value)
	{
		char Buffer[3];

		sprintf(Buffer, "%01D", Value);
		return (String(Buffer));
	}

	String Convert::Decimal(u16 Value)
	{
		char Buffer[5];

		sprintf(Buffer, "%01D", Value);
		return (String(Buffer));
	}

	String Convert::Decimal(u32 Value)
	{
		char Buffer[9];

		sprintf(Buffer, "%01D", Value);
		return (String(Buffer));
	}

	String Convert::Decimal(u64 Value)
	{
		char Buffer[17];

		sprintf(Buffer, "%01D", Value);
		return (String(Buffer));
	}
}
#pragma once

#include <cstdint>

namespace PCD8544
{
	namespace Driver
	{
		void Initialize(const int SerialDataInput, const int SerialClockInput, const int ModeSelect, const int ChipEnable, const int ResetInput);
		void Execute(const std::uint8_t instruction);
		void WriteData(const std::uint8_t data);
	}
}

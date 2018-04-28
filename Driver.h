#pragma once

#include <cstdint>

namespace PCD8544
{
	namespace Driver
	{
		void Initialize(const int SerialDataInput, const int SerialClockInput, const int ModeSelect, const int ChipEnable, const int ResetInput);
		void Execute(const std::uint8_t instruction);
		void WriteData(const std::uint8_t data);

		namespace Instruction
		{
			constexpr std::uint8_t FunctionSet = 0x20;

			constexpr std::uint8_t DisplayControl = 0x08;
			constexpr std::uint8_t SetYAddress = 0x40;
			constexpr std::uint8_t SetXAddress = 0x80;

			namespace Extended
			{
				constexpr std::uint8_t TemperatureControl = 0x04;
				constexpr std::uint8_t BiasSystem = 0x10;
				constexpr std::uint8_t SetVop = 0x80;
			}
		};
	}
}

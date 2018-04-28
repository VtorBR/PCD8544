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
		}

		namespace InstructionSet
		{
			constexpr std::uint8_t Basic = 0x0;
			constexpr std::uint8_t Extended = 0x1;
		}

		namespace DisplayConfiguration
		{
			constexpr std::uint8_t Blank = 0b000;
			constexpr std::uint8_t AllOn = 0b001;
			constexpr std::uint8_t Normal = 0b100;
			constexpr std::uint8_t Inverse = 0b101;
		}

		namespace MemoryAddressing
		{
			constexpr std::uint8_t Horizontal = 0b00;
			constexpr std::uint8_t Vertical = 0b10;
		}
	}
}

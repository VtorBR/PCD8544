#include "Display.h"
#include "Driver.h"
#include <cassert>

namespace PCD8544
{
	namespace Display
	{
		static FrameBuffer buffer = { 0 };

		void Initialize(const int SerialDataInput, const int SerialClockInput, const int ModeSelect, const int ChipEnable, const int ResetInput, const std::uint8_t Contrast)
		{
			assert(Contrast < 0x80);

			Driver::Initialize(SerialDataInput, SerialClockInput, ModeSelect, ChipEnable, ResetInput);

			Driver::Execute(Driver::Instruction::FunctionSet | Driver::InstructionSet::Extended);
			Driver::Execute(Driver::Instruction::Extended::BiasSystem | 0x4);
			Driver::Execute(Driver::Instruction::Extended::SetVop | Contrast);
			Driver::Execute(Driver::Instruction::FunctionSet | Driver::InstructionSet::Basic);
			Driver::Execute(Driver::Instruction::DisplayControl | Driver::DisplayConfiguration::Normal);
		}

		void SetPixel(const std::size_t x, const std::size_t y, const bool value)
		{
			assert(Width > x);
			assert(Height > y);

			if (value)
			{
				buffer[(y / 8) * Width + x] |= 1 << (y % 8);
			}
			else
			{
				buffer[(y / 8) * Width + x] &= !(1 << (y % 8));
			}
		}

		void SetByte(const std::size_t index, const std::uint8_t value)
		{
			assert(index < buffer.size());
			buffer[index] = value;
		}

		void Refresh()
		{
			Driver::Execute(Driver::Instruction::SetYAddress);
			Driver::Execute(Driver::Instruction::SetXAddress);

			for (const std::uint8_t data : buffer)
			{
				Driver::WriteData(data);
			}

			Driver::Execute(Driver::Instruction::SetYAddress);
		}
	}
}

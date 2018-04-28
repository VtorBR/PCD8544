#include "Display.h"
#include "Driver.h"
#include <cassert>

namespace PCD8544
{
	namespace Display
	{
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
	}
}

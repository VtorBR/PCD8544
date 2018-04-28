#include "Driver.h"
#include <wiringPi.h>
#include <chrono>
#include <thread>

namespace PCD8544
{
	namespace Driver
	{
		static int SCLK, SDIN, DC, SCE, RES;

		void Initialize(const int SerialDataInput, const int SerialClockInput, const int ModeSelect, const int ChipEnable, const int ResetInput)
		{
			SDIN = SerialDataInput;
			SCLK = SerialClockInput;
			DC = ModeSelect;
			SCE = ChipEnable;
			RES = ResetInput;

			pinMode(SDIN, OUTPUT);
			pinMode(SCLK, OUTPUT);
			pinMode(DC, OUTPUT);
			pinMode(SCE, OUTPUT);
			pinMode(RES, OUTPUT);

			digitalWrite(SCE, LOW);

			digitalWrite(RES, LOW);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			digitalWrite(RES, HIGH);
		}

		void WriteByte(const std::uint8_t data);

		void Execute(const std::uint8_t instruction)
		{
			digitalWrite(DC, LOW);
			WriteByte(instruction);
		}

		void WriteData(const std::uint8_t data)
		{
			digitalWrite(DC, HIGH);
			WriteByte(data);
		}

		void WriteByte(const std::uint8_t data)
		{
			std::uint8_t bitMask = 0b10000000;
			while (0 != bitMask)
			{
				digitalWrite(SDIN, !!(data & bitMask));

				digitalWrite(SCLK, HIGH);
				std::this_thread::sleep_for(std::chrono::microseconds(25));
				digitalWrite(SCLK, LOW);

				bitMask >>= 1;
			}
		}
	}
}

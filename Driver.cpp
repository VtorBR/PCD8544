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
	}
}

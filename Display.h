#pragma once

#include <cstddef>
#include <array>

namespace PCD8544
{
	namespace Display
	{
		constexpr std::size_t Width = 84;
		constexpr std::size_t Height = 48;
		using FrameBuffer = std::array<std::uint8_t, Width * Height / 8>;

		void Initialize(const int SerialDataInput, const int SerialClockInput, const int ModeSelect, const int ChipEnable, const int ResetInput, const std::uint8_t Contrast);

		void SetPixel(const std::size_t x, const std::size_t y, const bool value);
		void SetByte(const std::size_t index, const std::uint8_t value);
		void SetBuffer(const FrameBuffer & value);

		void Refresh();
	}
}

#pragma once

#include <cstdint>
#include <string>

namespace PCD8544
{
	namespace Graphics
	{
		void DrawGlyph(const std::uint8_t line, const std::uint8_t x, const std::uint8_t & character);
		void Write(std::uint8_t line, std::uint8_t x, const std::string & text);
	}
}

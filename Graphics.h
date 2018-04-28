#pragma once

#include <cstdint>
#include <string>

namespace PCD8544
{
	namespace Graphics
	{
		void Write(const std::uint8_t line, const std::uint8_t x, const std::string & text);
	}
}

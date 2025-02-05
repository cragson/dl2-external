#pragma once

#include <memory>

#include "osmium/Memory/Process/process.hpp"

#include "dl2_cheat.hpp"

namespace Globals
{
	inline auto g_pProcess = std::make_unique< process >();

	inline auto g_pCheat = std::make_unique< dl2_cheat >();
}
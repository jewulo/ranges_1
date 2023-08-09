#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>
#include <iomanip> // quoted

namespace r6
{
	void run()
	{
		const std::string firstStr = "Hello Super World";
		const std::string secondStr = "Hello Amazing World";

		std::cout << "mismatch for " << std::quoted(firstStr)
			<< " and " << std::quoted(secondStr) << '\n';

		// standard version:
		auto [first, second] = std::mismatch(std::begin(firstStr), std::end(firstStr),
			std::begin(secondStr));
		{
			const auto pos = std::distance(begin(firstStr), first);
			std::cout << "std::mismatch: at pos " << pos << '\n';
		}

		// ranges version:
		auto res = std::ranges::mismatch(firstStr, secondStr);
		{
			const auto pos = std::distance(begin(firstStr), res.in1);
			std::cout << "std::ranges::mismatch: at pos " << pos << '\n';
		}
	}
}

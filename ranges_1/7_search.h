#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>
#include <functional> // searchers
#include <iomanip>

namespace r7
{
	void run()
	{
		const std::string testString = "Hello Super World";
		const std::string needle = "Super";

		std::cout << "looking for " << std::quoted(needle)
			<< " in " << std::quoted(testString) << '\n';

		// standard version:
		auto it = std::search(testString.begin(), testString.end(),
			std::boyer_moore_searcher(needle.begin(), needle.end()));

		if (it != testString.end()) {
			const auto pos = std::distance(testString.begin(), it);
			std::cout << "std::search: found at pos " << pos << '\n';
		}

		// ranges version:
		auto res = std::ranges::search(testString, needle);
		if (!res.empty()) {
			const auto first = std::distance(testString.begin(), res.begin());
			const auto last = std::distance(testString.begin(), res.end());
			std::cout << "std::ranges::search: found between "
				<< first << " and " << last << '\n';
		}

		// ranges version using projections
		const std::string testString2 = "hello abc world";
		const std::string needle2 = "ABC";
		std::cout << "looking for " << std::quoted(needle2) << " in "
			<< std::quoted(testString2) << '\n';

		res = std::ranges::search(testString2, needle2,
			std::ranges::equal_to{}, ::toupper, ::toupper);

		if (!res.empty()) {
			const auto first = std::distance(testString2.begin(), res.begin());
			const auto last = std::distance(testString2.begin(), res.end());
			std::cout << "std::ranges::search: found between "
				<< first << " and " << last << '\n';
		}

	}
}


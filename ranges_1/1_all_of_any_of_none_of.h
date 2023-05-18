#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>

namespace r1a
{
    void run()
    {
        const std::vector nums = { 1, 2, 3, -4, 5, 6, 7, 8 };

        auto is_positive = [](const auto& v) { return v > 0; };

        // standard version:
        auto res = std::all_of(begin(nums), end(nums), is_positive);
        std::cout << "std::all_of: " << res << '\n';

        res = std::any_of(begin(nums), end(nums), is_positive);
        std::cout << "std::any_of: " << res << '\n';

        // ranges version:
        res = std::ranges::all_of(nums, is_positive);
        std::cout << "std::ranges::all_of: " << res << '\n';

        res = std::ranges::any_of(nums, is_positive);
        std::cout << "std::ranges::any_of: " << res << '\n';

        std::cout << '\n';
        std::cout << '\n';
    }
}

namespace r1b
{
    struct Product {
        std::string name_;
        double value_{ 0.0 };
    };

    void run()
    {
        const std::vector<Product> prods {
            { "box", 10.0 },
            { "tv", 100.0 },
            { "none", -1.0 }
        };

        
        auto is_positive_val = [](const Product& p) {
            return p.value_ > 0;
        };

        // standard version:
        auto res = std::all_of(begin(prods), end(prods), is_positive_val);
        std::cout << "std::all_of: " << res << '\n';

        res = std::any_of(begin(prods), end(prods), is_positive_val);
        std::cout << "std::any_of: " << res << '\n';

        auto is_positive = [](const auto& v) { return v > 0; };

        // ranges version:
        res = std::ranges::all_of(prods, is_positive, &Product::value_);
        std::cout << "std::ranges::all_of: " << res << '\n';

        res = std::ranges::any_of(prods, is_positive, &Product::value_);
        std::cout << "std::ranges::any_of: " << res << '\n';

        std::cout << '\n';
        std::cout << '\n';
    }
}


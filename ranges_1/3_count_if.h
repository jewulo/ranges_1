#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>

namespace r3
{
    struct Product {
        std::string name_;
        double value_{ 0.0 };
    };

    void run()
    {
        const std::vector<Product> prods {
            { "box", 10.0 },{ "tv", 100.0 }, { "none", -1.0 },
            { "car", 1000.0 }, { "toy", 40.0 }, { "none", 0.0 }
        };

        // standard version:    
        auto res = std::count_if(begin(prods), end(prods), [](const Product& p) {
            return p.name_.starts_with("no");
            });
        std::cout << "std::count_if: " << res << '\n';

        // ranges version:
        res = std::ranges::count_if(prods, [](const Product& p) {
            return p.name_.starts_with("no");
            });
        std::cout << "std::ranges::count_if: " << res << '\n';

        // alternative version for "none":
        res = std::ranges::count(prods, std::string{"none"}, & Product::name_);
        std::cout << "std::ranges::count: " << res << '\n';

        std::cout << '\n';
    }
}

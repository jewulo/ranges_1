#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>

namespace r2
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

        auto out = [](const auto& v) { std::cout << v << ", "; };

        // standard version:
        std::cout << "std::for_each: \n";
        std::for_each(begin(prods), end(prods), [](const Product& p) {
            std::cout << p.name_ << ", " << p.value_ << '\n';
        });

        std::cout << "std::for_each only names reverse: \n";
        std::for_each(rbegin(prods), rend(prods), [](const Product& p) {
            std::cout << p.name_ << '\n';
         });

        // ranges version:
        std::cout << "std::ranges::for_each: \n";
        std::ranges::for_each(prods, [](const Product& p) {
            std::cout << p.name_ << ", " << p.value_ << '\n';
            });

        std::cout << "std::ranges::for_each only names in reverse: \n";
        std::ranges::for_each(prods | std::views::reverse,
            out, &Product::name_);

        std::cout << '\n';
        std::cout << '\n';
    }
}

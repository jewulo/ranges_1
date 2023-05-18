#pragma once

#include <array>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>

namespace r5
{
    struct Product {
        std::string name_;
        double value_{ 0.0 };

        friend bool operator==(const Product& a, const Product& b) {
            return a.name_ == b.name_ && abs(a.value_ - b.value_) < 0.0001;
        }
    };

    void run()
    {
        const std::vector<Product> prods {
            { "box", 10.0 }, { "default", 0.0 }, { "tv", 100.0 }, { "rocket", 10000.0 },
            { "car", 1000.0 }, { "toy", 40.0 }, { "none", 0.0 }, { "ball", 40.0 }
        };

        const std::vector<Product> invalids {
            {"default", 0.0 }, { "none", 0.0 }
        };

        // standard version:    
        auto it = std::find_first_of(begin(prods), end(prods), begin(invalids), end(invalids));
        if (it != end(prods)) {
            std::cout << "std::find_first_of: " << it->name_ << " at: "
                << std::distance(begin(prods), it) << '\n';
            auto it2 = std::find_first_of(std::next(it), end(prods), begin(invalids), end(invalids));
            if (it2 != end(prods))
                std::cout << "std::find_first_of: " << it2->name_ << " at: "
                << std::distance(begin(prods), it2) << '\n';
        }

        // ranges version:
        const std::array<std::string, 2> arrInvalids{"default", "none"};
        auto res = std::ranges::find_first_of(prods, arrInvalids,
            std::ranges::equal_to{}, & Product::name_);
        if (res != end(prods)) {
            const auto pos = std::distance(begin(prods), res);
            std::cout << "std::ranges::find_first_of: " << res->name_
                << " at: " << pos << '\n';

            auto res2 = std::ranges::find_first_of(prods | std::views::drop(pos + 1), arrInvalids,
                std::ranges::equal_to{}, & Product::name_);
            if (res2 != end(prods)) {
                std::cout << "std::ranges::find_first_of: " << res2->name_
                    << " at: " << std::distance(begin(prods), res2) << '\n';
            }
        }

        std::cout << '\n';
    }
}


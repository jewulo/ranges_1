#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>

namespace r4
{
    struct Product {
        std::string name_;
        double value_{ 0.0 };
    };

    void run()
    {
        const std::vector<Product> prods {
            { "box", 10.0 }, { "tv", 100.0 }, { "rocket", 10000.0 },
            { "car", 1000.0 }, { "toy", 40.0 }, { "none", 0.0 }
        };

        // standard version:    
        auto it = std::find_if(begin(prods), end(prods), [](const Product& p) {
            return p.name_.starts_with("ro");
            });
        if (it != end(prods))
            std::cout << "std::find_if: " << it->name_ << '\n';

        // ranges version:
        auto res = std::ranges::find_if(prods, [](const Product& p) {
            return p.name_.starts_with("ro");
            });
        if (res != end(prods))
            std::cout << "std::ranges::find_if: " << res->name_ << '\n';

        // ranges version 2:
        auto res2 = std::ranges::find_if(begin(prods), end(prods), [](const Product& p) {
            return p.name_.starts_with("ro");
            });
        if (res2 != end(prods))
            std::cout << "std::ranges::find_if: " << res->name_ << '\n';

        std::cout << '\n';
    }
}

// error C2819: type 'std::ranges::dangling' does not have an overloaded member 'operator ->'
namespace r4_error_C2819
{
    struct Product {
        std::string name_;
        double value_{ 0.0 };
    };

    std::vector<Product> GetProds() {
        return {
            { "box", 10.0 }, {"tv", 100.0}, {"rocket", 10000.0},
            { "car", 1000.0 }, {"toy", 40.0}, {"none", 0.0}
        };
    }

    void run()
    {
        auto it = std::ranges::find_if(GetProds(), [](const Product& p) {
            return p.name_.starts_with("ro");
            });
        /*
        error C2819 : type 'std::ranges::dangling' does not have an overloaded member 'operator ->'
        std::cout << "std::ranges::find_if: " << it->name_ << '\n';

        */

        std::cout << '\n';
    }
}
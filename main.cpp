#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <string>

std::vector<std::string> generator(int amount, int length)
{
    std::random_device rd{};
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{seed};
    std::uniform_int_distribution rand{33, 126};

    std::vector<std::string> passwords{};

    for (int i{i}; i<=amount; ++i)
    {
        std::string password{};
        for (int i{1}; i<=length; ++i)
        {
            password += static_cast<char>(rand(mt));
        }
        passwords.push_back(password);
    }

    return passwords;
}

int main()
{
    
    return 0;
}
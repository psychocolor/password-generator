#include <iostream>
#include <limits>
#include <random>
#include <fstream>
#include <vector>
#include <string>
#include <string_view>

void saveToFile(const std::vector<std::string>& data, std::string filename)
{
    std::ofstream File(filename);
    for (int i{0}; i < data.size(); ++i)
    {
        if (i + 1 == data.size())
            File << data[i];
        else
            File << data[i] << '\n';
    }

    std::cout << "Password(s) generated, check " << filename << '\n';

    File.close();
}

std::vector<std::string> generator(int amount, int length)
{
    std::random_device rd{};
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{seed};
    std::uniform_int_distribution rand{33, 126};

    std::vector<std::string> passwords{};

    for (int i{1}; i<=amount; ++i)
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

int getVal(std::string_view text, int max)
{
    while (true)
    {
        std::cout << "Enter " << text << "(max. " << max << "): ";
        int val{};
        std::cin >> val;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error. Invalid input\n";
            continue;
        }

        if (std::cin)
        {
            if (val > 0 && val <= max)
                return val;
            else
                std::cerr << "Error. Input out of range.\n";
        }
    }
}

int main()
{
    int amount{getVal("amount of passwords to generate ", 100)};
    int length{getVal("desired length of each password ", 50)};

    std::vector<std::string> passwords{generator(amount, length)};
    saveToFile(passwords, "output.txt");

    return 0;
}
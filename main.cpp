#include <iostream>
#include <limits>
#include <random>
#include <fstream>
#include <vector>
#include <string>

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

int getAmount()
{
    while (true)
    {
        const int maxAmount{100};
        std::cout << "Enter amount of passwords to generate (max. " << maxAmount << "): ";
        int amount{};
        std::cin >> amount;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. Invalid character\n";
            continue;
        }

        if (std::cin)
        {
            if (amount > 0 && amount <= maxAmount)
                return amount;
            else
                std::cerr << "Error. Amount out of range.\n";
        }
    }
}

int getLength()
{
    while (true)
    {
        const int maxLength{50};
        std::cout << "Enter desired length of each password (max. " << maxLength << "): ";
        int length{};
        std::cin >> length;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. Invalid character\n";
            continue;
        }

        if (std::cin)
        {
            if (length > 0 && length <= maxLength)
                return length;
            else
                std::cerr << "Error. Amount out of range.\n";
        }
    }
}

int main()
{
    int amount{getAmount()};
    int length{getLength()};
    std::vector<std::string> passwords{generator(amount, length)};
    saveToFile(passwords, "output.txt");

    return 0;
}
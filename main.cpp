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
        File << data[i] << '\n';
    }

    std::cout << "Password(s) generated, check output.txt\n";

    File.close();
}

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
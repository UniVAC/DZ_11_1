#include <iostream>
#include <string>

std::string encrypt_caesar(std::string str, int x)
{
    if (x > 26) x = x - 26 * (x / 26);
    else if (x < -26) x = x - 26 * (x / 26);

    int sim;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            sim = (int)str[i] + x;
            if (sim > 'z') str[i] = sim - 26;
            else if (sim < 'a') str[i] = sim + 26;
            else str[i] = sim;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            sim = (int)str[i] + x;
            if (sim > 'Z') str[i] = sim - 26;
            else if (sim < 'A') str[i] = sim + 26;
            else str[i] = sim;
        }
    }
    return str;
}

std::string decrypt_caesar(std::string text, int x)
{
    return encrypt_caesar(text, -x);
}

int main() {

    std::string text;
    int position;
    

    std::cout << "Inpute text: " << std::endl;
    std::getline(std::cin, text);

    std::cout << "Shift to: ";
    std::cin >> position;

    std::cout << encrypt_caesar(text, position) << std::endl;
    std::cout << "\nThe decrypted text: \n";
    std::cout << decrypt_caesar(encrypt_caesar(text, position), position);
}
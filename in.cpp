#include <iostream>
#include <string>
namespace luhn
{
    bool valid(std::string inputNumber)
    {
        std::string output = "";
        std::string input = "";
        int sum = 0;
        int j = 0;
        int l = static_cast<int>(inputNumber.length());
        for (int i = 0; i < l; i++)
        {
            if (inputNumber[i] != ' ')
            {
                input += inputNumber[i];
                if (!isdigit(inputNumber[i]))
                    return false;
            }
        }
        int n=static_cast<int>(input.length());
        std::cout << input << std::endl;
        for (int i = n - 1; i >= 0; i--)
        {

            if ((n - i) % 2 == 0)
            {
                int temp = (input[i] - '0') * 2;
                if (temp > 9)
                    output += std::to_string(temp - 9);
                else
                    output += std::to_string(temp);
            }
            else
                output += input[i];

            sum += output[j] - '0';
            j++;
            std::cout << output << std::endl;
        }

        std::cout << sum << std::endl;
        if (sum % 10 == 0 && n > 1)
            return true;
        return false;
    }
} // namespace luhn

int main(void)
{
    std::cout << luhn::valid("234 567 891 234") << std::endl;
}
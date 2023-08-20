#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    string output = "";
    string s1, s2;

    if (str1.length() >= str2.length())
        s1 = str1, s2 = str2;
    else
        s1 = str2, s2 = str1;

    int l1 = str1.length();
    int l2 = str2.length();

    while (l2 != 0)
    {
        int temp = l2;
        l2 = l1 % l2;
        l1 = temp;
    }
    int gcd = l1;

    for (int i = 1; i < gcd; i++)
    {
        int x = 0, y = 0;
        if (gcd % i != 0)
            continue;
        bool isRepeating = true;
        while (x < s1.length() && y < s2.length())
            for (int k = 0; k <= i; k++)
                if (s1[x++] != s2[k] || s2[y++] || s2[k])
                {
                    isRepeating = false;
                    break;
                }
        if (isRepeating)
        {
            for (int j = 0; j <= i; j++)
                output += s2[j];
            break;
        }
    }
    return output;
}

int main(void)
{
    cout << gcdOfStrings("ABCABC", "ABC") << endl;
}
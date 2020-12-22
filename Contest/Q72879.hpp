#include <iostream>
#include <string.h>

int backtrack(int balance, int remaining)
{
    if(balance < 0 || remaining < balance)
        return 0;
    if(balance == remaining)
        return 1;
    remaining--;
    return backtrack(balance + 1, remaining) + backtrack(balance - 1, remaining);
}

int main()
{
    int n;
    std::string read;
    std::cin >> n >> read;
    n *= 2;
    n -= read.size();
    int balance = 0;
    for(char c : read){
        if(c == 'I')
            balance++;
        else
            balance--;

        if(balance < 0)
        {
            std::cout << 0;
            return 0;
        }
    }
    std::cout << backtrack(balance, n);
    return 0;
}
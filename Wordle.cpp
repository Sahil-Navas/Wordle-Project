#include <iostream>
#include <string>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

void checkWord(std::string guess[], std::string ans[], int size)
{
    bool check; 
    for(int i = 0; i <= size; i++)
    {
        for(int i = 0; i <= size; i++)
        {
            int count = 0;
            if(guess[count] != ans[i])
            {
                count++;
            } else if (guess[count] == ans[i])
            {
                check = true;
                break;
            } else
            {
                check = false;
            }
        }
        if(ans[i] == guess[i])
        {
           std::cout << GREEN << guess[i];
           
        }else if(guess[i] != ans[i] && check == true)
        {
            std::cout << YELLOW << guess[i];
        }else if (guess[i] != ans[i] && check != true)
        {   
            std::cout << RED << "_";
        }
    }
}

int main()
{
    // Note to future self, indexing always starts at 0, but # of elements inside [] start at 1
    std::string ans[5] = {"B", "R", "A", "I", "N"};
    std::string guess[5];
    std::string enteredWord;

    std::cout << "Please type in the 5 letter word:" << std::endl;
    std::cout << "(Note): Type in uppercase for the whole word" << std::endl;
    getline(std::cin, enteredWord);

    for(int i = 0; i <= 4; i++)
    {
        guess[i] = enteredWord[i];
    }

    std::cout << ans[0] << std::endl;
    std::cout << enteredWord[0] << std::endl;
    
    checkWord(guess, ans, 4);

}
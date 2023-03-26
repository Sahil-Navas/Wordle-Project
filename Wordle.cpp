#include <iostream>
#include <string>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"


void findBestRound(int roundOneTries, int roundTwoTries, int roundThreeTries);

bool checkWord(std::string guess[], std::string ans[], int size)
{
    bool check;
    int counter;
    for(int i = 0; i <= size; i++)
    {
        for(int j = 0; j <= size; j++)
        {
            if(guess[i] == ans[j]) {
                check = true;
                break;
            }
            check = false;
        }
        if(!check) {
            std::cout << RED << guess[i];
        }
        else if(check && ans[i] == guess[i])
        {
            std::cout << GREEN << guess[i];
            counter++;

        } else if(check && guess[i] != ans[i])
        {
            std::cout << YELLOW << guess[i];
        }
    }
    if(counter == 5)
    {
        return true;
    }
    return false;
}


int main()
{
    // Note to future self, indexing always starts at 0, but # of elements inside [] start at 1
    std::string roundOneAns[5] = {"B", "R", "A", "I", "N"};
    std::string roundTwoAns[5] = {"E", "R", "R", "O", "R"};
    std::string roundThreeAns[5] = {"W", "A", "T", "C", "H"};
    std::string roundAns[5];
    int roundOneTries = 0;
    int roundTwoTries = 0;
    int roundThreeTries = 0;

    std::string guess[5];
    std::string enteredWord;
    std::cout << "Welcome to Wordle game" << std::endl;
    for(int f = 0; f < 3; f++)
    {
        std::cout << "You are on round " << f + 1 << std::endl;
        switch(f)
        {
            case 0:
                std::copy(roundOneAns, roundOneAns + 5, roundAns);
                break;
            case 1:
                std::copy(roundTwoAns, roundTwoAns + 5, roundAns);
                break;
            case 2:
                std::copy(roundThreeAns, roundThreeAns + 5, roundAns);
                break;
        }
        std::cout << "Please type in the 5 letter word:" << std::endl;
        std::cout << "(Note): Type in uppercase for the whole word" << std::endl;
        try {
            int tries = 0;
            bool checkAnswer;
            for(int k = 0; k < 6; k++)
            {
                std::cout << WHITE << std::endl;
                getline(std::cin, enteredWord);
                if(enteredWord.empty() || enteredWord.length() > 5 || enteredWord.length() < 5)
                {
                    throw "Please enter a 5 letter word";
                }
                for(int i = 0; i <= 4; i++)
                {
                    guess[i] = enteredWord[i];
                }
                checkAnswer = checkWord(guess, roundAns, 4);
                if (checkAnswer)
                {
                    tries = k;
                    std::cout << std::endl;
                    std::cout << "You've passed the round with " << tries+1 << " number of tries" << std::endl;
                    break;
                }
                tries = k;
            }
            switch(f)
            {
                case 0:
                    roundOneTries = tries;
                    break;
                case 1:
                    roundTwoTries = tries;
                    break;
                case 2:
                    roundThreeTries = tries;
                    break;
            }
            std::cout << std::endl;
            if(tries == 5 && checkAnswer == false)
            {
                std::cout << "You've passed 6 tries, good luck next time" << std::endl;
            }
        }
        catch (const char *err)
        {
            std::cout << err << std::endl;
            exit(0);
        }
    }
    findBestRound(roundOneTries,roundTwoTries,roundThreeTries);

}

void findBestRound(int roundOneTries, int roundTwoTries, int roundThreeTries)
{
    int tries[3] = {roundOneTries, roundTwoTries, roundThreeTries};
    int min = tries[0];

    for(int i = 0; i < 3; i++)
    {
        if(min > tries[i])
        {
            min = tries[i];
        }
    }

    if(min == roundOneTries)
    {
        std::cout << "Round one has the least amount of tries at " << min + 1 << std::endl;
    } else if(min == roundTwoTries)
    {
        std::cout << "Round two has the least amount of tries at " << min + 1 << std::endl;
    } else if (min == roundThreeTries)
    {
        std::cout << "Round three has the least amount of tries at " << min + 1 << std::endl;
    }
}

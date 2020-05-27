#include <iostream>
#include <time.h>

void Welcome(int Level, int Max)
{
    std::cout << "\n\nYou need to break into a room to steal "<< Max - 1 
    <<" files\nTo break in, you need to enter a 3-digit code\n";
    std::cout << "You have " << Max - Level  << " files left to steal.\n\n";
}

int game(int Current, int CurrentOne)
{
    Welcome(Current, CurrentOne);

    //In-game value declaration
    srand(time(NULL));
    int ValueA = 5*rand()%Current  + 3;
    int ValueB = 2*rand()%Current  + 4;
    int ValueC = 3*rand()%Current  + 1;
    int Sum = ValueA + ValueB + ValueC;
    int Product = ValueA * ValueB * ValueC;

    //Question Display
    std::cout << "The sum of the codes is " << Sum << "\n";
    std::cout << "The product of the codes is " << Product << "\n";
    std::cout << "One of the digits is " << ValueC;

    //Player input
    int GuessA;
    int GuessB;
    int GuessC;
    std::cout << std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Passing or repeat conditions
    if(GuessSum == Sum && GuessProduct == Product )
    {
        std::cout << "You got it !";
        return 2;
    }
    else
    {
        std::cout << "Wrong code.";
        return 3;
    }
}

int main()
{
    int const MaxDiff = 3;
    int Diff = 1;
    int Life = 0;   //Declare lives left
    while(Diff <= MaxDiff)
    {
        int Game = game(Diff, MaxDiff+1);

        if(Game == 2) //Passes to next level
        {
            ++Diff;
            std::cout << std::endl;
            std::cout << "\nAttemps left: " << MaxDiff - Life << std::endl;
        }
        else // Stays in the same level
        {
            ++Life; 
            std::cout << "\nAttemps left: " << MaxDiff - Life << std::endl;
            if(Life == 3) //Loses after 3 attempts
            {
                ++ Diff;++ Diff;++ Diff;++ Diff; 
            }
        }  
    }

    if(Diff == MaxDiff )
    {
        std::cout <<"\nYou got all the files, hurry and get back safely.";
    }
    else
    {
        std::cout << "\nMission terminated due to failure, get out of there.";
    }
    return 0;
}
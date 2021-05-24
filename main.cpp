#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "You are a secret agent breaking into a level: " << Difficulty;
    std::cout << " secure room...\nEnter the correct three digit code to continue!\n\n";
}

bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    // declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print data to terminal
    std::cout << "+ There are three numbers in the code...";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct << std::endl;


    // set player guess variables
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\nYou entered: " << GuessA << ", " << GuessB << " & " << GuessC;

    // calculate sum and product values
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // check if players guess is correct
    if (GuessSum == CodeSum && CodeProduct == GuessProduct) {
        std::cout << "\n Well done! You have secured the files... onto the next room.\n\n";
        return true;
    } else {
        std::cout << "\n Incorrect code! Please try again.\n\n";
        return false;
    }
}


int main() {

    // seed random to time
    srand(time(NULL));

    int LevelDifficulty = 1;
    int MaxLevel = 5;

    while (LevelDifficulty < MaxLevel) {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n==> Great work Agent! You are a master code breaker!\n";
    return 0;
}
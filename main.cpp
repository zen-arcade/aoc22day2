#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int shapeScore(char shape)
{
    if(shape=='X')
        return 1;
    if(shape=='Y')
        return 2;
    if(shape=='Z')
        return 3;
}

int roundScore1(std::string movePair)
{
    //A,X = rock    B,Y = paper     C,Z = scissors  first column opponent, second column player
    if(movePair=="A X"||movePair=="B Y"||movePair=="C Z") //draw --> 3 points
        return 3;
    if(movePair=="A Z"||movePair=="B X"||movePair=="C Y") //loss --> 0 points
        return 0;
    if(movePair=="A Y"||movePair=="B Z"||movePair=="C X") //win ---> 6 points
        return 6;
}

int roundScore2(std::string movePair)
{
    char opMove=movePair[0];
    char roundEnd=movePair[2];
    switch(opMove)
    {
    case 'A':
        switch(roundEnd)
        {
        case 'X': //need to lose (0pt) against rock: use scissors (3pt)
            return 3;
        case 'Y': //need to draw (3pt) against rock: use rock (1pt)
            return 4;
        case 'Z': //need to win (6pt) against rock: use paper (2pt)
            return 8;
        }
    case 'B':
        switch(roundEnd)
        {
        case 'X': //need to lose (0pt) against paper: use rock (1pt)
            return 1;
        case 'Y': //need to draw (3pt) against paper: use paper(2pt)
            return 5;
        case 'Z': //need to win (6pt) against paper: use scissors (3pt)
            return 9;
        }
    case 'C':
        switch(roundEnd)
        {
        case 'X': //need to lose (0pt) against scissors: use paper (2pt)
            return 2;
        case 'Y': //need to draw (3pt) against scissors: use scissors (3pt)
            return 6;
        case 'Z': //need to win (6pt) against scissors: use rock (1pt)
            return 7;
        }

    }
}

int main()
{
    std::ifstream line{"input.txt"};
    std::string round;
    //std::vector<std::string> stratGuide;
    int i{0},score1{0},score2{0};
    while(std::getline(line,round))
    {
        char yrMove=round[2];
        score1+=shapeScore(yrMove)+roundScore1(round);
        score2+=roundScore2(round);
    }
    std::cout<<score1<<'\n'<<score2<<'\n';
    return 0;
}

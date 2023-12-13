#include "fraction.h"

#include <iostream>
#include <stdexcept>

using namespace std;
enum class Block
{
    Mo1,
    Mo2,
    Mo3,
    Mo4,
    Mo5,
    Mo6,
    Mo7,
    Di1,
    Di2,
    Di3,
    Di4,
    Di5,
    Di6,
    Di7,
    Mi1,
    Mi2,
    Mi3,
    Mi4,
    Mi5,
    Mi6,
    Mi7,
    Do1,
    Do2,
    Do3,
    Do4,
    Do5,
    Do6,
    Do7,
    Fr1,
    Fr2,
    Fr3,
    Fr4,
    Fr5,
    Fr6,
    Fr7,
    Sa1,
    Sa2,
    Sa3,
    Sa4,
    Sa5,
    Sa6,
    Sa7
};
enum Tag
{
    MO,
    DI,
    MI,
    DO,
    FR,
    SA
};

void aufgabe_14_a(Block input)
{
    const int casted_int_block = static_cast<int>(input);
    const int divided = casted_int_block / 7;
    switch (static_cast<char>(divided))
    {
    case 0:
        cout << "Montag" << endl;
        ;
        break;
    case 1:
        cout << "Dienstag" << endl;
        ;
        break;
    case 2:
        cout << "Mittwoch" << endl;
        break;
    case 3:
        cout << "Donnerstag" << endl;
        break;
    case 4:
        cout << "Fritag" << endl;
        break;
    case 5:
        //  cout << "Samstag" << endl;
        /*  return Tag::SA; */
        break;
    default:
        cout << "Invalid Argument" << endl;
        throw invalid_argument("LMAO Cannot happen due to Strong Enum usage as input");
        /*        return Tag::DI; */

        //    invalid_argument; // invalid_argument
        break;
    }
}
bool aufgabe14_b(Block input)
{
    return static_cast<int>(input) >= 24 || static_cast<int>(input) <= 27 ? true : false;
}

void aufgabe_16()
{
    // local variables!
    Fraction f1;
    Fraction f2;
    Fraction result;
    readFraction(f1);
    readFraction(f2);
    cout << endl
         << "Erster Bruch: ";
    printFraction(f1);
    cout << "Zweiter Bruch: ";
    printFraction(f2);
    // Addition
    result = add(f1, f2);
    cout << endl
         << "Addition: ";
    printFraction(result);
    // Substraktion
    result = subtract(f1, f2);
    cout << "Subtraktion: ";
    printFraction(result);
    // Multiplikation
    result = multiply(f1, f2);
    cout << "Multiplikation: ";
    printFraction(result);
    // Division
    result = divide(f1, f2);
    cout << "Division: ";
    printFraction(result);
}

int main()
{
    aufgabe_16();

    /*    const Block testcase = Block::Di1;
       aufgabe_14_a(testcase);
       cout << aufgabe14_b(Block::Di6) << endl; */
    return 0;
}

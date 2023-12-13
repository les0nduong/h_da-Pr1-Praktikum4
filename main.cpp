#include "fraction.h"

#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std ;
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
        /*  return TagSA; */
        break;
    default:
        cout << "Invalid Argument" << endl;
        throw invalid_argument("LMAO Cannot happen due to Strong Enum usage as input");
        /*        return TagDI; */

        //    invalid_argument; // invalid_argument
        break;
    }
}
bool aufgabe14_b(Block input)
{
    return static_cast<int>(input) >= 24 && static_cast<int>(input) <= 27 ? true : false;
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
 struct Result
{
    bool success;
    string reason;
    void printReason()
    {
        cout << this->reason << endl;
    }
} ;

template <typename T>
Result checkSorting(vector<T> input)
{
    Result output;
    if (input.size() == 0)
    {
        output.reason = "Es gibt nichts auf dem Array";
        output.success = false;
        return output;
    }
    else if (input.size() != 0)
    {
         vector<T> duplicated = input;
        sort(duplicated.begin(), duplicated.end());

        for (long long unsigned int i = 0; i < duplicated.size(); i++)
        {
            if (input[i] != duplicated[i])
            {
                output.reason = "";
                output.reason += ".";
                output.reason += static_cast<char>(i);
                output.reason += " steht nicht in seine korrekte Position";
                output.success = false;
                return output;
                break;
            }
        }
    }
    
        output.success = true;
        return output;
    
}
template <typename T>
void addData(vector<T> &inputArr)
{
    T inputUser;
    cin >> inputUser;
    inputArr.push_back(inputUser);
}

template <typename T>
Result printData(vector<T> input)
{
    Result output;

    if (input.size() == 0)
    {
        output.reason = "Es gibt nichts auf dem Array";
        output.success = false;
        return output;
    }
    else
    {
        for (const auto &element : input)
        {
            cout << element << std::endl;
        }
        output.success = true;
        return output;
    }
}
template <typename T>
void inner(vector<T> input)

{

    string menu_input{};
    char menu_input_ok{};
    bool inMenu = true;
    while (inMenu)
    {
    cout << "" << endl
                  << "" << endl
                  << "Menu:" << endl
                  << "(1) Wert eingeben" << endl
                  << "(2) Werte ausgeben" << endl
                  << "(3) Wert suchen" << endl
                  << "(4) Auf Sortierung prüfen" << endl
                  << "(x) Ende" << endl
                  << "" << endl
                  << "" << endl;
        cin >> menu_input;

        if (menu_input.length() > 1)
        {
            menu_input_ok = 'r';
        }
        else
        {
            menu_input_ok = menu_input[0];
        }

        switch (menu_input_ok)
        {
        case '1':
        {
       
            addData(input);
        }
        break;
        case '2':
        {
            Result print = printData(input);
            if (print.success == false)
            {
                print.printReason();
            }
        }
        break;
        case '3':

            break;

        case '4':
        {
            Result sortedResult = checkSorting(input);
            if (sortedResult.success == false)
            {
                sortedResult.printReason();
            }
        }
        break;

        case 'x':
        {
            inMenu = false;
        }
        break;

        default:
        {
            cout << "" << endl
                      << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                      << "Bitte geben Sie eine gültige Option an" << endl
                      << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                      << "" << endl;
        }
        break;
        }
    }
}

void aufgabe_15()
{

    bool select = true;
    while (select)
    {
        char menu_input_ok{};
        string menu_input{};
        cout << "" << endl
             << "" << endl
             << "(S) Array mit String" << endl
             << "(I) Array mit Interger" << endl
             << "(F) Array mit Float" << endl
             << "(E) Ende" << endl
             << "" << endl
             << "" << endl;
        cin >> menu_input;
        if (menu_input.length() > 1)
        {
            menu_input_ok = 'r';
        }
        else
        {
            menu_input_ok = menu_input[0];
        }
        switch (menu_input_ok)
        {
        case 's':
        {
            vector<string> data{};
            inner(data);
        }
        break;

        default:
            break;
        }
    }
}

int main()
{
    aufgabe_15();

    /*    const Block testcase = BlockDi1;
       aufgabe_14_a(testcase);
       cout << aufgabe14_b(BlockDi6) << endl; */
    return 0;
}

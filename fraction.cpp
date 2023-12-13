#include "fraction.h"
#include <iostream>
#include <iomanip>
using namespace std;

void ignoreLine()
{
    cin.ignore(259, '\n');
}
void printFraction(Fraction &f)
{
    cout << f.numerator << " / " << f.denominator << endl;
}

void readFraction(Fraction &f)
{
    int inputAbove{}, inputLower{};
    bool validAbove = false;
    bool validLower = false;
    while (!validAbove)
    {
        if (!inputAbove)
        {
            cout << "Zaehler: ";

            cin >> inputAbove;
            cout << endl;
        }
        if (!cin)
        {
            cout << "Falsche Eingabe!" << endl;
            cin.clear();
            ignoreLine();
        }

        else
        {

            validAbove = true;
            ignoreLine();
        }
    }
    while (!validLower)
    {

        if (!inputLower)
        {

            cout << "Nenner: ";
            cin >> inputLower;
            cout << endl;
        }

        if (!cin)
        {
            cout << "Falsche Eingabe!" << endl;
            cin.clear();
            ignoreLine();
        }
        if (inputLower == 0)
        {
            cout << "bruh" << endl;
        }
        else

        {
            validLower = true;
            ignoreLine();
        }
    }

    f.numerator = inputAbove;
    f.denominator = inputLower;
}
int gcd(int p, int q) // Berechnung größter gemeinsamer Teiler
{
    while (q != 0)
    {
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
}
void cancel(Fraction &fRef) // Kürzen des Bruchs
{
    int gcdNumDenom = gcd(fRef.numerator, fRef.denominator);
    fRef.numerator /= gcdNumDenom;
    fRef.denominator /= gcdNumDenom;
}
void format(Fraction &fRef) // Bruch formatieren (Aufruf am Ende der vier
{                           // ... Grundrechenarten und von readFraction)
    cancel(fRef);
    if (fRef.denominator < 0)
    {
        fRef.numerator = -fRef.numerator;
        fRef.denominator = -fRef.denominator;
    }
    else if (fRef.denominator == 0)
        cout << "Nenner darf nicht Null sein!" << endl;
}

Fraction add(Fraction &f1Ref, Fraction &f2Ref)
{
    Fraction output{};

    output.numerator = f1Ref.numerator * f2Ref.denominator + f2Ref.numerator * f1Ref.denominator;
    output.denominator = f1Ref.denominator * f2Ref.denominator;
    format(output);

    return output;
}

Fraction subtract(Fraction &f1Ref, Fraction &f2Ref)
{
    Fraction output{};

    output.numerator = f1Ref.numerator * f2Ref.denominator - f2Ref.numerator * f1Ref.denominator;
    output.denominator = f1Ref.denominator * f2Ref.denominator;
    format(output);

    return output;
}

Fraction multiply(Fraction &f1Ref, Fraction &f2Ref)
{
    Fraction output{};

    output.numerator = f1Ref.numerator * f2Ref.numerator;
    output.denominator = f1Ref.denominator * f2Ref.denominator;
    format(output);

    return output;
}

Fraction divide(Fraction &f1Ref, Fraction &f2Ref)
{

    Fraction output{};
    if (f2Ref.numerator == 0)
    {
        output = f1Ref;
        return output;
    }

    output.numerator = f1Ref.numerator * f2Ref.denominator;
    output.denominator = f1Ref.denominator * f2Ref.numerator;
    format(output);

    return output;
}

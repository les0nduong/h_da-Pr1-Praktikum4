#include <iostream>
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
enum Tag {
MO, DI, MI, DO, FR, SA
};

void aufgabe_14_a(Block input)
{
    const int casted_int_block = static_cast<int>(input);
    const int divided = casted_int_block / 7;
    switch (static_cast<char>(divided))
    {
    case 0:
        cout<<"Montag"<<endl;;
        break;
    case 1:
        cout<<"Dienstag"<<endl;;
        break;
    case 2:
        cout<<"Mittwoch"<<endl;
        break;
    case 3:
        cout<<"Donnerstag"<<endl;
        break;
    case 4:
        cout<<"Fritag"<<endl;
        break;
    case 5:
        cout<<"Samstag"<<endl;
        break;
    default:
        cout<<"Invalid Argument"<<endl;;//invalid_argument
        break;
    }
}
bool aufgabe14_b(Block input){
    return static_cast<int>(input) >= 24 || static_cast<int>(input) <= 27 ? true : false;
}
int main()
{
    const Block testcase = Block::Di1;
    aufgabe_14_a(testcase);
    cout << aufgabe14_b(Block::Di6) << endl;
    return 0;
}
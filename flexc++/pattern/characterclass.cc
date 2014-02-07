#include "pattern.ih"

Pattern Pattern::characterClass(States &states, CharClass &charClass)
{
    Pair pair = states.next2();

    states[pair.first] = State(CHARSET, charClass.str(), pair.second);

//    cerr << "Pattern::characterClass: ";
//    for (auto ch: charClass.str())
//    {
//        if (isprint(ch)) 
//            cerr << ch;
//        else
//            cerr << ' ' << (int)ch << ' ';
//    }
//    cerr << "\n"
//            "States: " << pair.first << " .. " << pair.second << '\n';

    Pattern ret(pair);

    ret.d_length = not charClass.empty();

    return ret;
}

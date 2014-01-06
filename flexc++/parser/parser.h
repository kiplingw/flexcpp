// Generated by Bisonc++ V2.09.04 on Mon, 16 Jan 2012 21:40:37 +0100

#ifndef Parser_h_included
#define Parser_h_included

#include <string>

#include "../state/state.h"
#include "../block/block.h"
#include "../options/options.h"

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "../scanner/scanner.h"

class States;
class Rules;

#undef Parser
class Parser: public ParserBase
{
    typedef std::pair<size_t, size_t> Pair;

    Options &d_options;

    // $insert scannerobject
    Scanner d_scanner;
    std::string const &d_matched;   // text matched at the last lex() call.
    Block   d_block;

    bool d_boln             = false;    // rule starts at boln
    bool d_doError          = true;     // use the error() function at ERRORs
    bool d_warnCarets       = false;    // carets in a RE
    bool d_warnDollars      = false;    // dollars in a RE

    bool d_usesLOP          = false;
    Pattern d_lhs;                      // lhs, rhs patterns used with the LOP
    Pattern d_rhs;

    bool d_printTokens;

    size_t d_parentheses = 0;
    size_t d_tokenCount = 0;

    std::string d_expect;

    Rules &d_rules;
    States &d_states;

//FBB   remove:
    size_t d_lopStartCondition = 0;         // startconditions for LOPs

    static int s_ignoreToken;
    static std::string s_lastMsg;

    public:
        Parser(Rules &rules, States &states);
        int parse();
        void cleanup();     // prepare Mstream tags, define accessor variables
                            // and show filenames
    private:
        Pattern eolnDollar();

        void orAction();    // sets the action of the last rule but one to 
                            // the last rule's action

        void reset();       // prepare the parser for a new regex 
                            // (resetting tokencount and warning flags)

        Pattern boln();
        Pattern dollar();
        Pattern quotes();
        Pattern lookahead(Pattern const &left, Pattern const &right);
        Pattern interval(Pattern &regex, Interval const &interval);

        Pattern escape();                                   // .ih
        Pattern str();                                      // .ih
        Pattern rawText();                                  // .ih
        Pattern rawText(std::string const &str);            // .ih

        void assignBlock();
        void noActions();

//FBB        void lopRule(LopRule &rule);

        void addRule(Pattern const &rule, bool resetMs = false);
//FBB        void addBlockRule(Pattern const &rule);

        void block();
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();  

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
        void exceptionHandler__(std::exception const &exc);
};

#endif






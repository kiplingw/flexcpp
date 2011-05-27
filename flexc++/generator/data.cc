#include "generator.ih"

Generator::Map Generator::s_insert =
{
    // $insert-key         function called
    {"DFAbases",            &Generator::DFAbases},
    {"DFAs",                &Generator::dfas},
    {"RFCs",                &Generator::rfcs},
    {"actions",             &Generator::actions},
    {"baseclass_h",         &Generator::baseClassH},
    {"class_h",             &Generator::classH},
    {"class_ih",            &Generator::classIH},
    {"inputInterface",      &Generator::inputInterface},
    {"inputImplementation", &Generator::inputImplementation},
    {"debug",               &Generator::debug},
    {"debugDecl",           &Generator::debugDecl},
    {"debugFunctions",      &Generator::debugFunctions},
    {"debugIncludes",       &Generator::debugIncludes},
    {"debugInit",           &Generator::debugInit},
    {"debugStep",           &Generator::debugStep},
    {"declarations",        &Generator::declarations},
    {"inlineLexFunction",   &Generator::inlineLexFunction},
    {"lexFunctionDecl",     &Generator::lexFunctionDecl},
    {"namespace-close",     &Generator::namespaceClose},    
    {"namespace-open",      &Generator::namespaceOpen},
    {"namespace-use",       &Generator::namespaceUse},
    {"ranges",              &Generator::ranges},
    {"startCondNames",      &Generator::startCondNames},
    {"tailCount",            &Generator::tailCount},
};

char const *Generator::s_baseFlag = "\\@";
size_t const Generator::s_baseFlagSize = 2; // backslash and @

string Generator::s_matchedTextFunction = "d_scanner.YYText()";
string Generator::s_scannerTokenFunction = "d_scanner.yylex()";



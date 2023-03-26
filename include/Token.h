//
// Created by 周诣鑫 on 2023/3/25.
//

#ifndef NEW_LANGUAGE_TOKEN_H
#define NEW_LANGUAGE_TOKEN_H

#include <iostream>
#include <map>

using namespace std;

typedef string TokenType;

enum token {
    _ILLEGAL,
    _EOF,
    _IDENT,
    _INT,
    _ASSIGN,
    _PLUS,
    _COMMA,
    _SEMICOLON,
    _LPAREN,
    _RPAREN,
    _LBRACE,
    _RBRACE,
    _FUNCTION,
    _LET,
    _MINUS,
    _BANG,
    _ASTERISK,
    _SLASH,
    _LT,
    _GT,
    _TRUE,
    _FALSE,
    _IF,
    _ELSE,
    _RETURN,
    _EQ,
    _NOT_EQ,
    _ELT,
    _EGT,
};

map<token, string> token_map{
        {_ILLEGAL, "ILLEGAL"},
        {_EOF, "EOF"},
        {_IDENT, "IDENT"},
        {_INT, "INT"},
        {_ASSIGN, "="},
        {_PLUS, "+"},
        {_MINUS, "-"},
        {_BANG, "!"},
        {_ASTERISK, "*"},
        {_SLASH, "/"},
        {_EQ, "=="},
        {_NOT_EQ, "!="},

        { _LT, "<" },
        {_ELT,"<="},
        { _GT, ">" },
        {_EGT,">="},

        { _COMMA, "," },
        { _SEMICOLON, ";" },
        { _LPAREN, "(" },
        { _RPAREN, ")" },
        { _LBRACE, "{" },
        { _RBRACE, "}" },

        { _FUNCTION, "FUNCTION" },
        { _LET, "LET" },
        { _TRUE, "TRUE" },
        { _FALSE, "FALSE" },
        { _IF, "IF" },
        { _ELSE, "ELSE" },
        { _RETURN, "RETURN" },
};

map<string, token> keywords = {
        {"fn",     _FUNCTION},
        {"let",    _LET},
        {"true",   _TRUE},
        {"false",  _FALSE},
        {"if",     _IF},
        {"else",   _ELSE},
        {"return", _RETURN}
};

TokenType LookupIdent(const string &ident) {
    if (auto iter = keywords.find(ident);iter != keywords.end()) {
        return token_map[iter->second];
    }
    return token_map[_IDENT];
}

class Token {
public:
    TokenType TType;
    string Literal;
public:
    Token() = default;

    Token(token t, char ch) : TType(token_map.at(t)), Literal(string(1, ch)) {};

    Token(token t, string s) : TType(token_map.at(t)), Literal(move(s)) {}

    ~Token() = default;
};


#endif //NEW_LANGUAGE_TOKEN_H

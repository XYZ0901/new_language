//
// Created by 周诣鑫 on 2023/3/25.
//

#ifndef NEW_LANGUAGE_LEXER_H
#define NEW_LANGUAGE_LEXER_H

#include <iostream>
#include <memory>

#include "Token.h"

using namespace std;

class Lexer {
public:
    explicit Lexer(string input);

    shared_ptr<Token> NextToken();

private:
    void readChar();
    string readNumber();
    string readIdentifier();
    void skipWhitespace();
private:
    string input;
    int position{};
    int readPosition{};
    char ch{};
};

bool isLetter(char ch){
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

bool isDigit(char ch){
    return '0' <= ch && ch <= '9';
}

Lexer::Lexer(string input) : input(std::move(input)) {
    readChar();
}

shared_ptr<Token> Lexer::NextToken() {
    auto tok = make_shared<Token>();

    skipWhitespace();

    switch (ch) {
        case '=':
            tok = make_shared<Token>(token::_ASSIGN,ch);
            break;
        case ';':
            tok = make_shared<Token>(token::_SEMICOLON,ch);
            break;
        case '(':
            tok = make_shared<Token>(token::_LPAREN,ch);
            break;
        case ')':
            tok = make_shared<Token>(token::_RPAREN,ch);
            break;
        case ',':
            tok = make_shared<Token>(token::_COMMA,ch);
            break;
        case '+':
            tok = make_shared<Token>(token::_PLUS,ch);
            break;
        case '{':
            tok = make_shared<Token>(token::_LBRACE,ch);
            break;
        case '}':
            tok = make_shared<Token>(token::_RBRACE,ch);
            break;
        case 0:
            tok = make_shared<Token>(token::_EOF,ch);
            break;
        default:
            if (isLetter(ch)){
                tok->Literal = readIdentifier();
                tok->TType = LookupIdent(tok->Literal);
                return tok;
            }else if(isDigit(ch)){
                tok->TType = token_map.at(token::_INT);
                tok->Literal = readNumber();
                return tok;
            }else{
                tok = make_shared<Token>(token::_ILLEGAL,ch);
            }
    }
    readChar();
    return tok;
}

void Lexer::readChar() {
    if (readPosition >= input.size()) {
        ch = 0;
    } else {
        ch = input.at(readPosition);
    }
    position = readPosition;
    readPosition += 1;
}

string Lexer::readNumber() {
    auto _position = position;
    while(isDigit(ch)){
        readChar();
    }
    return input.substr(_position,position-_position);
}

string Lexer::readIdentifier() {
    auto _position = position;
    while (isLetter(ch)){
        readChar();
    }
    return input.substr(_position,position-_position);
}

void Lexer::skipWhitespace() {
   while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r'){
       readChar();
   }
}

#endif //NEW_LANGUAGE_LEXER_H

//
// Created by 周诣鑫 on 2023/3/25.
//

#include "gtest/gtest.h"

#include <Lexer.h>

TEST(Lexer, l1) {
    auto l = Lexer("=+(){},;");

    Token tests[] = {
            {token::_ASSIGN,    '='},
            {token::_PLUS,      '+'},
            {token::_LPAREN,    '('},
            {token::_RPAREN,    ')'},
            {token::_LBRACE,    '{'},
            {token::_RBRACE,    '}'},
            {token::_COMMA,     ','},
            {token::_SEMICOLON, ';'},
            {token::_EOF,       0},
    };

    for (auto &t: tests) {
        auto tok = l.NextToken();
        ASSERT_EQ(t.TType, tok->TType);
        ASSERT_EQ(t.Literal, tok->Literal);
    }
}

TEST(Lexer, l2) {
    auto l = Lexer("let five = 5;\n"
                   "let ten = 10;\n"
                   "let add = fn(x, y) {\n"
                   "   x + y;\n"
                   "};\n"
                   "let result = add(five, ten);");

    Token tests[] = {
            {token::_LET,       "let"},
            {token::_IDENT,     "five"},
            {token::_ASSIGN,    "="},
            {token::_INT,       "5"},
            {token::_SEMICOLON, ";"},
            {token::_LET,       "let"},
            {token::_IDENT,     "ten"},
            {token::_ASSIGN,    "="},
            {token::_INT,       "10"},
            {token::_SEMICOLON, ";"},
            {token::_LET,       "let"},
            {token::_IDENT,     "add"},
            {token::_ASSIGN,    "="},
            {token::_FUNCTION,  "fn"},
            {token::_LPAREN,    "("},
            {token::_IDENT,     "x"},
            {token::_COMMA,     ","},
            {token::_IDENT,     "y"},
            {token::_RPAREN,    ")"},
            {token::_LBRACE,    "{"},
            {token::_IDENT,     "x"},
            {token::_PLUS,      "+"},
            {token::_IDENT,     "y"},
            {token::_SEMICOLON, ";"},
            {token::_RBRACE,    "}"},
            {token::_SEMICOLON, ";"},
            {token::_LET,       "let"},
            {token::_IDENT,     "result"},
            {token::_ASSIGN,    "="},
            {token::_IDENT,     "add"},
            {token::_LPAREN,    "("},
            {token::_IDENT,     "five"},
            {token::_COMMA,     ","},
            {token::_IDENT,     "ten"},
            {token::_RPAREN,    ")"},
            {token::_SEMICOLON, ";"},
            {token::_EOF,       0},
    };

    for (auto &t: tests) {
        auto tok = l.NextToken();
        ASSERT_EQ(t.TType, tok->TType);
        ASSERT_EQ(t.Literal, tok->Literal);
    }
}

TEST(Lexer, l3) {
    auto l = Lexer("let five = 5;\n"
                   "let ten = 10;\n"
                   "     let add = fn(x, y) {\n"
                   "         x + y;\n"
                   "};\n"
                   "let result = add(five, ten);\n"
                   "     !-/*5;\n"
                   "     5 < 10 > 5;");

    Token tests[] = {
            {token::_LET, "let"},
            {token::_IDENT, "five"},
            {token::_ASSIGN, "="},
            {token::_INT, "5"},
            {token::_SEMICOLON, ";"},
            {token::_LET, "let"},
            {token::_IDENT, "ten"},
            {token::_ASSIGN, "="},
            {token::_INT, "10"},
            {token::_SEMICOLON, ";"},
            {token::_LET, "let"},
            {token::_IDENT, "add"},
            {token::_ASSIGN, "="},
            {token::_FUNCTION, "fn"},
            {token::_LPAREN, "("},
            {token::_IDENT, "x"},
            {token::_COMMA, ","},
            {token::_IDENT, "y"},
            {token::_RPAREN, ")"},
            {token::_LBRACE, "{"},
            {token::_IDENT, "x"},
            {token::_PLUS, "+"},
            {token::_IDENT, "y"},
            {token::_SEMICOLON, ";"},
            {token::_RBRACE, "}"},
            {token::_SEMICOLON, ";"},
            {token::_LET, "let"},
            {token::_IDENT, "result"},
            {token::_ASSIGN, "="},
            {token::_IDENT, "add"},
            {token::_LPAREN, "("},
            {token::_IDENT, "five"},
            {token::_COMMA, ","},
            {token::_IDENT, "ten"},
            {token::_RPAREN, ")"},
            {token::_SEMICOLON, ";"},
            {token::_BANG, "!"},
            {token::_MINUS, "-"},
            {token::_SLASH, "/"},
            {token::_ASTERISK, "*"},
            {token::_INT, "5"},
            {token::_SEMICOLON, ";"},
            {token::_INT, "5"},
            {token::_LT, "<"},
            {token::_INT, "10"},
            {token::_GT, ">"},
            {token::_INT, "5"},
            {token::_SEMICOLON, ";"},
            {token::_EOF,       0},
    };

    for (auto &t: tests) {
        auto tok = l.NextToken();
        ASSERT_EQ(t.TType, tok->TType);
        ASSERT_EQ(t.Literal, tok->Literal);
    }
}

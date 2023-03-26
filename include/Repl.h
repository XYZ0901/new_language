//
// Created by 周诣鑫 on 2023/3/26.
//

#ifndef NEW_LANGUAGE_REPL_H
#define NEW_LANGUAGE_REPL_H

#include <iostream>
#include <string>

#include <Lexer.h>


const string PROMPT = ">> ";

void Start() {
    cout << PROMPT;
    string scan;
    while (getline(cin, scan)) {
        Lexer l(scan);
        for (auto tok = l.NextToken();
             tok->TType != token_map.at(_EOF); tok = l.NextToken()) {
            cout << "token::type: " << tok->TType
                 << " token::Literal: " << tok->Literal << endl;
        }
        cout << PROMPT;
    }

}

#endif //NEW_LANGUAGE_REPL_H

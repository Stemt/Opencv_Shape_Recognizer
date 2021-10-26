#include "Tokenizer.hpp"
#include <iostream>
#include <string>
#include <algorithm>

Tokenizer::Tokenizer(const std::string& str)
:str(str),pos(0)
{
    setNewString(str);
}

Tokenizer::~Tokenizer()
{}

char Tokenizer::getNextChar()
{
    char next_char = 0;
    if(str.size() > 0){
        next_char = str.back();
    }
    return next_char;
}

Token Tokenizer::getNextToken()
{
    if(tokens.size() > 0){
        Token token = tokens.back();
        tokens.pop_back();
        pos += token.length();
        return token;
    }else{
        Token token(END_OF_FILE,"");
        return token;
    }
}

bool Tokenizer::isColon(char ch, Token& token)
{
    return ch == ':';
}

bool Tokenizer::isComma(char ch, Token& token)
{
    return ch == ',';
}

bool Tokenizer::isNumber(char ch, Token& token)
{
    if(token.length() > 0 && ch == '.' && token.string.find('.') == std::string::npos){
        if(ch == '.'){
            token.type = DECIMAL_NUMBER;
        }
        return true;
    }else if(token.length() > 0 && ch == '.' && token.string.find('.') != std::string::npos){
         std::string tmp("");
         tmp.push_back(ch);
        throw std::invalid_argument("multiple instances of  '" + tmp + "' found in number: " + token.string + "\n");
    }else{
        return digits.find(ch) != std::string::npos;
    }
}

bool Tokenizer::isLetter(char ch, Token& token)
{
    return (letters.find(ch) != std::string::npos);
}

bool Tokenizer::isNewLine(char ch, Token& token)
{
    return ch == '\n' || ch == '\r';
}

bool Tokenizer::isWhiteSpace(char ch, Token& token)
{
    return ch == ' ' || ch == '\t';
}

bool Tokenizer::isOpenBrace(char ch, Token& token)
{
    return ch == '(' && token.length() == 0;
}

bool Tokenizer::isClosingBrace(char ch, Token& token)
{
    return ch == ')' && token.length() == 0;
}

bool Tokenizer::isOperator(char ch, Token& token)
{
    for(size_t i = 0; i < operators.size(); i++){
        if(ch == operators[i] && token.length() < 2){
            token.type = HASHTAG_OPERATOR;
            return true;
        }
    }
    return false;
}

size_t Tokenizer::getPos()
{
    return pos;
}

void Tokenizer::setNewString(const std::string& str){
    this->str = str;
    pos = 0;
    tokens.clear();

    int n = this->str.length();

    for (int i = 0; i < n / 2; i++)
        std::swap(this->str[i], this->str[n - i - 1]);

    while(this->str.size() > 0){
        char current_char = getNextChar();

        Token token(END_OF_FILE,"");

        bool (Tokenizer::*check_char)(char ch, Token& token) = nullptr;
        if(isNumber(current_char, token)){
            check_char = &Tokenizer::isNumber;
            token.type = INTEGER_NUMBER;
        }else if(isLetter(current_char, token)){
            check_char = &Tokenizer::isLetter;
            token.type = WORD;
        }else if(isNewLine(current_char, token)){
            check_char = &Tokenizer::isNewLine;
            token.type = NEW_LINE;
        }else if(isColon(current_char, token)){
            check_char = &Tokenizer::isColon;
            token.type = COLON;
        }else if(isComma(current_char, token)){
            check_char = &Tokenizer::isComma;
            token.type = COMMA;
        }else if(isWhiteSpace(current_char, token)){
            check_char = &Tokenizer::isWhiteSpace;
            token.type = WHITE_SPACE;
        }else if(isOpenBrace(current_char, token)){
            check_char = &Tokenizer::isOpenBrace;
            token.type = OPEN_BRACE;
        }else if(isClosingBrace(current_char, token)){
            check_char = &Tokenizer::isClosingBrace;
            token.type = CLOSING_BRACE;
        }else if(isOperator(current_char, token)){
            check_char = &Tokenizer::isOperator;
        }else{
            tokens.push_back(token);
            break;
        }

        token.string.push_back(current_char);
        this->str.pop_back();

        current_char = getNextChar();

        while((this->*check_char)(current_char, token) && this->str.size() > 0)
        {
            token.string.push_back(current_char);
            this->str.pop_back();
            current_char = getNextChar();
        }

        tokens.push_back(token);

    }

    n = tokens.size();

    for (int i = 0; i < n / 2; i++)
        std::swap(tokens[i], tokens[n - i - 1]);
}
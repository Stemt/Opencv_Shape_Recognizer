#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <iostream>

enum token_type {
    NONE,
    WHITE_SPACE,
    INTEGER_NUMBER,
    DECIMAL_NUMBER,
    WORD,
    NEW_LINE,
    COMMA,
    COLON,
    OPEN_BRACE,
    CLOSING_BRACE,
    PLUS_OPERATOR,
    MINUS_OPERATOR,
    MULLTIPLY_OPERATOR,
    DIVIDE_OPERATOR,
    MODULUS_OPERATOR,
    HASHTAG_OPERATOR,
    END_OF_FILE
};

struct Token{
    Token(token_type type, const std::string& string): type(type), string(string){};
    token_type type;
    std::string string;
    size_t length() const { return string.length(); };
};

class Tokenizer{
    private:
        size_t pos;
        std::string str;
        /**
         * @brief gets the next character out of the string.
         * @return character.
         */
        char getNextChar();
        /**
         * @brief checks if the character is a whitespace.
         * @param ch character to check.
         * @param token tokeninfo.
         * @return true if whitespace.
         */
        bool isWhiteSpace(char ch, Token& token);
        /**
         * @brief checks if the character is a number.
         * @param ch character to check.
         * @param token tokeninfo
         * @return true if number.
         */
        bool isNumber(char ch, Token& token);
        /**
         * @brief check if the character is a letter.
         * @param ch character to check.
         * @param token tokeninfo.
         * @return true if letter.
         */
        bool isLetter(char ch, Token& token);
        /**
         * @brief checks if the character is a comma.
         * @param ch character to check.
         * @param token token info.
         * @return  true if comma.
         */
        bool isComma(char ch, Token& token);
        /**
         * @brief checks if the character is a colon.
         * @param ch character to check.
         * @param token token info.
         * @return true if colon.
         */
        bool isColon(char ch, Token& token);
        /**
         * @brief checks if the character is a newline.
         * @param ch character to check.
         * @param token token info.
         * @return true if newline.
         */
        bool isNewLine(char ch, Token& token);
        /**
         * @brief checks if character is a openbrace.
         * @param ch character to check.
         * @param token token info.
         * @return true if openbrace.
         */
        bool isOpenBrace(char ch, Token& token);
        /**
         * @brief checks if character is a closingbrace.
         * @param ch character to check.
         * @param token token info.
         * @return true if closingbrace.
         */
        bool isClosingBrace(char ch, Token& token);
        /**
         * @brief checks if character is a operator.
         * @param ch character to check.
         * @param token token info.
         * @return true if operator.
         */
        bool isOperator(char ch, Token& token);
        std::string digits = "1234567890";
        std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMONPQRSTUVWXYZ-";
        std::string operators = "=+-*/%.#";
        std::vector<Token> tokens;
    public:
        /**
         * @brief constructor.
         * @param str
         */
        Tokenizer(const std::string& str);
        /**
         * @brief destructor.
         */
        ~Tokenizer();
        /**
         * @brief gets the next token.
         * @return a token.
         */
        Token getNextToken();
        /**
         * @brief get the position.
         * @return return position.
         */
        size_t getPos();
        /**
         * @brief sets a new string.
         * @param str
         * @return (void)
         */
        void setNewString(const std::string& str);
};



#endif
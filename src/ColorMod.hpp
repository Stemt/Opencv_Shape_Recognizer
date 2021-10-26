
#ifndef COLORMOD_H_
#define COLORMOD_H_

#include <ostream>

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        /**
         * @brief 
         * @param pCode
         */
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        /**
         * @brief 
         * @param os
         * @param mod
         */
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif
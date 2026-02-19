
#ifndef RPN_HPP
 #define RPN_HPP
#include <iostream>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class RPN{
    public:
        RPN();
        RPN(std::string arg);
        RPN(const RPN & other);
        RPN & operator=(const RPN & other);
        ~RPN();

        void process_expression(std::string arg);
        int do_operation(int first, int second, int oper);
        int is_operator(char c);
        //void parse_expression(std::string arg);

        //could make this into one error message (digit out of range 0-9 only)
        class DigitOutOfBounds : public std::exception{
            public:
                virtual const char * what() const throw();
        };
       /*  class DigitBelowZero : public std::exception{
            public:
                virtual const char * what() const throw();
        };
        class DoubleDigits : public std::exception{
            public:
                virtual const char * what() const throw();
        }; */
        class WrongExpression : public std::exception{
            public:
                virtual const char * what() const throw();
        };
      /*   class NoExpression : std::exception{
            public:
                virtual const char * what() const throw();
        }; */
    private:
        std::stack<int> _stack;
};

#endif
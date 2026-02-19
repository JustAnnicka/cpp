
#include "RPN.hpp"

RPN::RPN(){
    std::cerr << "Construction failed. No input" << std::endl;
    throw(WrongExpression());
}

RPN::RPN(std::string arg){
    std::cout << "RPN string constructor called" << std::endl;
    process_expression(arg);
}
RPN::RPN(const RPN & other){
    std::cout << "Copy constructor called" << std::endl;
    if (this != &other)
    {
        this->_stack = other._stack;
    }
}
RPN & RPN::operator=(const RPN & other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
/*         _stack.clear();
        for(size_t i = other._stack.size(); i >= 0; --i)
            _stack.push(other._stack[i]); */
    }
    return (*this);
}

RPN::~RPN(){
    std::cout << "RPN destructor called" << std::endl;
}

void RPN::process_expression(std::string arg){

    int check = 0;
    int x;
    for(size_t i = 0; i < arg.size(); i++){
        std::cout << "Enter : " << arg[i] << std::endl;
        if (arg[i] == ' ')
            check = 0;
        else if (isdigit(arg[i]))
        {
            _stack.push(static_cast<int>(arg[i]));
            check++;
        }
        else if (int o = is_operator(arg[i]) != 0)
        {
            if (_stack.size() < 2)  
                throw(WrongExpression());
            std::cout << "Enter " << std::endl;
            x = _stack.top();
            _stack.pop();
            x = do_operation(x, _stack.top(), 0);
            _stack.pop();
            _stack.push(x);
            check++;
        }
        else if (check > 1)
            throw(WrongExpression());
    }
    /* for(std::string::iterator it = arg.begin(); it != arg.end(); ++it){
        std::cout << "Enter : " << *it << std::endl;
        if (*it == ' ')
            check = 0;
        else if (isdigit(*it))
        {
            _stack.push(static_cast<int>(*it));
            check++;
        }
        else if (int o = is_operator(*it) != 0)
        {
            x = _stack.top();
            _stack.pop();
            x = do_operation(x, _stack.top(), 0);
            _stack.pop();
            _stack.push(x);
            check++;
        }
        else if (check > 1)
            throw(WrongExpression());
    } */
}

int RPN::is_operator(char c){
    //use enums
    if (c == '+')
        return (1);
    if (c == '-')
        return (2);
    if (c == '/')
        return (3);
    if (c == '*')
        return (4);
    return (0);
}

int RPN::do_operation(int first, int second, int oper){
    switch (oper)
    {
        case 1: //can do enums here
            return (first + second);
        case 2:
            return (first - second);
        case 3:
            return (first / second);
        case 4:
            return (first * second);
    }
   return (0);
}

// === EXCEPTIONS ===
const char * RPN::DigitOutOfBounds::what() const throw(){
    return ("Error: Digit out of bounds. Only accept 0 - 9");
}

const char * RPN::WrongExpression::what() const throw(){
    return ("Error: Wrong expression");
}

//if we find an operator we pop last two values and apply operator ->followed by pushing this value
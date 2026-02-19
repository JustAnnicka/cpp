
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
//check the copy of this as we have to go to the end and then reverse to push
    //or rather push into a temp from top then pop then use this new reverse stack to push into original and copy
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
    long x;

    for(size_t i = 0; i < arg.size(); i++){
        int o = is_operator(arg[i]);
        if (arg[i] == ' ')
            check = 0;
        else if (isdigit(arg[i]))
        {
            _stack.push(static_cast<long>(arg[i] - 48));
            if (_stack.top() < 0)
                throw(DigitOutOfBounds()); //dont need this covered by wrong expression
            check++;
            if (check > 1)
                throw(DigitOutOfBounds());
        }
        else if (o != 0)
        {
            if (_stack.size() < 2)  
                throw(WrongExpression());
            x = _stack.top();
            _stack.pop();
            x = do_operation(_stack.top(), x, o);
            _stack.pop();
            _stack.push(x);
            check++;
        }
        if (check > 1)
            throw(WrongExpression());
    }
    if (_stack.size() != 1)
        throw(WrongExpression());
    std::cout << _stack.top() << std::endl;
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
        case 1:
        {
            std::cout << first <<  " + " << second  << " = " << first + second << std::endl; 
            return (first + second);
        }
        case 2:
        {
            std::cout << first <<  " - " << second  << " = " << first - second << std::endl; 
            return (first - second);
        }
        case 3:
        {
            if (second == 0)
                throw(DivideByZero());
            std::cout << first <<  " / " << second  << " = " << first / second << std::endl; 
            return (first / second);
        }
        case 4:
        {
            std::cout << first <<  " * " << second  << " = " << first * second << std::endl; 
            return (first * second);
        }
/*         case 1: //can do enums here
            return (first + second);
        case 2:
            return (first - second);
        case 3:
            return (first / second);
        case 4:
            return (first * second); */
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

const char * RPN::DivideByZero::what() const throw(){
    return ("Error: Divide by Zero not permited");
}

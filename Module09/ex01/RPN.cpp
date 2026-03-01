
#include "RPN.hpp"

RPN::RPN(){
    std::cerr << "RPN constructor called" << std::endl;
   // throw(WrongExpression());
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
        this->_stack = other._stack;
    return (*this);
}

RPN::~RPN(){
   // std::cout << "RPN destructor called" << std::endl;
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
                throw(DigitOutOfBounds());
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
        return ('+');
    if (c == '-')
        return ('-');
    if (c == '/')
        return ('/');
    if (c == '*')
        return ('*');
    return (0);
}

int RPN::do_operation(int first, int second, int oper){
    switch (oper)
    {
        case '+':
        {
           // std::cout << first <<  " + " << second  << " = " << first + second << std::endl; 
            return (first + second);
        }
        case '-':
        {
           // std::cout << first <<  " - " << second  << " = " << first - second << std::endl; 
            return (first - second);
        }
        case '/':
        {
            if (second == 0)
                throw(DivideByZero());
           // std::cout << first <<  " / " << second  << " = " << first / second << std::endl; 
            return (first / second);
        }
        case '*':
        {
          //  std::cout << first <<  " * " << second  << " = " << first * second << std::endl; 
            return (first * second);
        }
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

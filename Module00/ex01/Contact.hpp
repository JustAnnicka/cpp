// CONTACT FIELDS
// first name (public)
// last name (public)
// nickname (public)
// phone number (private)
// darkest secret (private)
// Time of creation (public?) only needed to check for later when we assigne over 8 contacts

// Free to design the classes as I like but anything that will be used inside a class is private
// -> anything use outside the class is public

#include <iostream>

class Contact
{
    private:
        std::string secret;
        int phone_number;
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string time;
        void        set_phonenumber(int);
        Contact(/* args */);
        ~Contact();
};
class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area() {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

void    Contact::set_phonenumber(int number)
{
    phone_number = number;
}

// Contact::Contact(/* args */)
/*{

}

Contact::~Contact()
{

} */

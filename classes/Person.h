#include <string>

class Person{
    public:
        // Construct
        Person();
        Person(std::string first_name, std::string last_name);

        // Public Methods
        void set_first_name(std::string first_name);
        void set_last_name(std::string last_name);
        std::string get_first_name();
        std::string get_last_name();

    private:
        // Attributes
        std::string _first_name;
        std::string _last_name;
};
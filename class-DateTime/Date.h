#include <string>
#include <ctime>

class Date{
    public:
        // Construct
        Date();
        Date(int day, int month, int year);

        // Public Methods
        void set_day(int day);
        void set_month(int month);
        void set_year(int year);
        int get_day();
        int get_month();
        int get_year();
        int get_days_in_month(int month, int year);
        void add_days(int amount_days);
        std::string to_string();

    private:
        // Attributes
        int _day;
        int _month;
        int _year;

        // Private Methods
        void increase_day();
        void decrease_day();
};
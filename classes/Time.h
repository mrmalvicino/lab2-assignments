#include <string>
#include <ctime>

class Time{
    public:
        // Construct
        Time();
        Time(int second, int minute, int hour);

        // Public Methods
        void set_second(int second);
        void set_minute(int minute);
        void set_hour(int hour);
        int get_second();
        int get_minute();
        int get_hour();
        std::string to_string();

    private:
        // Attributes
        int _second;
        int _minute;
        int _hour;
};
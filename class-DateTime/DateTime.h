#include "Date.h"
#include "Time.h"

class DateTime{
    public:
        // Construct
        DateTime();
        DateTime(Date date, Time time);
        DateTime(int day, int month, int year, int second, int minute, int hour);

        // Public Methods
        void set_date(Date date);
        void set_time(Time time);
        void set_date(int day, int month, int year);
        void set_time(int second, int minute, int hour);
        Date get_date();
        Time get_time();
        std::string to_string();

    private:
        // Attributes
        Date _date;
        Time _time;
};
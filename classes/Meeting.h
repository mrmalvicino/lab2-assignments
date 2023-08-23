#include "Person.h"
#include "DateTime.h"

class Meeting{
    public:
        // Construct
        Meeting();

        // Public Methods
        void add_participant(std::string participant_first_name, std::string participant_last_name);
        std::string get_participant(int participant_index);
        int get_amount_of_participants();
        void set_date_time(DateTime date_time);
        void set_where(std::string where);
        void set_topic(std::string topic);
        void set_duration(int duration);
        DateTime get_date_time();
        std::string get_where();
        std::string get_topic();
        int get_duration();

    private:
        // Attributes
        Person _participants[5];
        int _amount_of_participants;
        DateTime _date_time;
        std::string _where;
        std::string _topic;
        int _duration;
};
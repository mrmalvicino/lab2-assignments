#include "Person.h"
#include "DateTime.h"

class Meeting{
    public:
        // Construct
        Meeting(int max_number_of_participants);
        ~Meeting();

        // Public Methods
        void addParticipant(std::string participant_first_name, std::string participant_last_name);
        std::string getParticipant(int participant_index);
        int getAmountOfParticipants();
        void setDateTime(DateTime date_time);
        void setWhere(std::string where);
        void setTopic(std::string topic);
        void setDuration(int duration);
        DateTime getDateTime();
        std::string getWhere();
        std::string getTopic();
        int getDuration();
        std::string toString();

    private:
        // Attributes
        int _max_amount_of_participants;
        Person *_participants;
        int _amount_of_participants;
        DateTime _date_time;
        std::string _where;
        std::string _topic;
        int _duration;
};
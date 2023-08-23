#include "Meeting.h"

// Construct

Meeting::Meeting(){
    _amount_of_participants = 0;
    _where = "N/A";
    _topic = "N/A";
    _duration = 0;
}

// Public Methods

void Meeting::add_participant(std::string participant_first_name, std::string participant_last_name){
    _participants[_amount_of_participants].set_first_name(participant_first_name);
    _participants[_amount_of_participants].set_last_name(participant_last_name);
    _amount_of_participants ++;
}

std::string Meeting::get_participant(int participant_index){
    std::string first_name = _participants[participant_index].get_first_name();
    std::string last_name = _participants[participant_index].get_last_name();

    return first_name + " " + last_name;
}

int Meeting::get_amount_of_participants(){
    return _amount_of_participants;
}

void Meeting::set_date_time(DateTime date_time){
    _date_time = date_time;
}

void Meeting::set_where(std::string where){
    _where = where;
}

void Meeting::set_topic(std::string topic){
    _topic = topic;
}

void Meeting::set_duration(int duration){
    if(0 <= duration){
        _duration = duration;
    }
}

DateTime Meeting::get_date_time(){
    return _date_time;
}

std::string Meeting::get_where(){
    return _where;
}

std::string Meeting::get_topic(){
    return _topic;
}

int Meeting::get_duration(){
    return _duration;
}
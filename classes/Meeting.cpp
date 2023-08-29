#include "Meeting.h"

// Construct

Meeting::Meeting(){
    _amount_of_participants = 0;
    _where = "N/A";
    _topic = "N/A";
    _duration = 0;
}

// Public Methods

void Meeting::addParticipant(std::string participant_first_name, std::string participant_last_name){
    _participants[_amount_of_participants].setFirstName(participant_first_name);
    _participants[_amount_of_participants].setLastName(participant_last_name);
    _amount_of_participants ++;
}

std::string Meeting::getParticipant(int participant_index){
    std::string participant_full_name = "";
    
    if(participant_index < _amount_of_participants){
        std::string first_name = _participants[participant_index].getFirstName();
        std::string last_name = _participants[participant_index].getLastName();

        participant_full_name = first_name + " " + last_name;
    }

    return participant_full_name;
}

int Meeting::getAmountOfParticipants(){
    return _amount_of_participants;
}

void Meeting::setDateTime(DateTime date_time){
    _date_time = date_time;
}

void Meeting::setWhere(std::string where){
    _where = where;
}

void Meeting::setTopic(std::string topic){
    _topic = topic;
}

void Meeting::setDuration(int duration){
    if(0 <= duration){
        _duration = duration;
    }
}

DateTime Meeting::getDateTime(){
    return _date_time;
}

std::string Meeting::getWhere(){
    return _where;
}

std::string Meeting::getTopic(){
    return _topic;
}

int Meeting::getDuration(){
    return _duration;
}

std::string Meeting::toString(){
    std::string date_time_string = _date_time.toString();
    std::string duration_string = std::to_string(_duration);
    std::string participants_string = "";

    for(int i = 0; i < getAmountOfParticipants(); i ++){ // Recorre cada participante de cada reunión
            if(i < getAmountOfParticipants() - 1){ // Solo para omitir la última coma
                participants_string += getParticipant(i) + ", ";
            } else{
                participants_string += getParticipant(i);
            }
        }

    return date_time_string + "\t" + _where + "\t" + _topic + "\t" + duration_string + "\t\t" + participants_string;
}
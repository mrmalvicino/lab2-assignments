#include <string>

class DataTransferObject{
    public:
        // Construct
        DataTransferObject();
        DataTransferObject(std::string text, char * & array, int size);
        ~DataTransferObject();

        // Public Methods
        void setSize(int size);
        int getSize();
        void setText(std::string text);
        void textToChar(char * & array);

    private:
        // Attributes
        int _size;
        char * _array;

        // Private Methods
        int getLenght(std::string text);
};
#ifndef CLASSES
#define CLASSES

#include "printsuccess.cpp" // <-- Includes "<IOSTREAM>" already
#include <uuid/uuid.h>
#include <string.h>
#include <string>


class TreeItem
{

  public:
    TreeItem(std::string name_str)
    {
      this->itemName = name_str;
      uuid_generate(this->UUID);

      char UUID_str[37];      // ex. "1b4e28ba-2fa1-11d2-883f-0016d3cca427" + "\0"
      uuid_unparse_lower(this->UUID, UUID_str);

      this->UUID_String = UUID_str;
    }

    std::string itemName;
    uuid_t UUID;
    std::string UUID_String;


    // Print all associated relevant values
    void printValues()
    {
      std::cout << "\n\n itemName  ==  " << itemName
                << "\n\n UUID  ==  " << UUID_String
                << "\n\n" << std::endl;
    }
};





#endif // CLASSES

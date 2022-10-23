#include <vector>
#include <uuid/uuid.h>

#include "printsuccess.cpp" // <-- Includes "<IOSTREAM>" already


struct TreeItem
{
  std::string itemName;
  uuid_t UUID;
};


int main()
{
  // uuid_t UUID;
  // uuid_generate(UUID);
  // TreeItem treeItem = 
  // {
  //   "Fat Albert",
  //   std::string aString{ UUID, UUID + 16 },
  // };

  printEndOfProgram();
  return 0;
}

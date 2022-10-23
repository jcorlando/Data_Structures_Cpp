#include "classes.cpp"

#include <vector>


class TableEntry
{
  public:
    TreeItem parent;
    std::vector<TreeItem> children;
    void printParentChildren()
    {
      ; // <---- Start working here. think
        // <---- of something to do here.
    }
};



int main()
{
  TreeItem treeItem_one("JabberWockey");
  TreeItem treeItem_two("BanderSnatch");
  TreeItem treeItem_three("SuperFly");
  treeItem_one.printValues();
  treeItem_two.printValues();
  treeItem_three.printValues();




  printEndOfProgram();
  return 0;
}

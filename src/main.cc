#include <Grid.h>
#include <Logger.h>
#include <PTrain.h>

#include <iostream>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "Required source file name argument" << std::endl;
    std::cout << "Usage: ptrain <file_name>" << std::endl;
    return 1;
  }

  std::string file_name = argv[1];

  PTrain::PTrain ptrain(file_name);
  while (ptrain.update());

  PTrain::Logger::log_line_dbg("Program has finished running");

  return 0;
}

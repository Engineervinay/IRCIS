#pragma once

#include <Logger.h>
#include <Grid.h>
#include <Runner.h>

#include <string>
#include <queue>
#include <memory>

namespace Ircis {
  class Ircis {
  public:
    Ircis(std::string input_file, bool quiet_mode=false)
      :runner_id_(0),
       log_(std::make_shared<Logger>("output.log", quiet_mode)),
       grid_(std::make_shared<Grid>(input_file)),
       new_runners_list_(std::make_shared<std::queue<RunnerInfo> >()) {
      runner_list_.emplace_back(runner_id_++, grid_, log_, new_runners_list_);
    }
    Ircis(std::string input_file, std::string output_file, bool quiet_mode=false)
      :runner_id_(0),
       log_(std::make_shared<Logger>(output_file, quiet_mode)),
       grid_(std::make_shared<Grid>(input_file)),
       new_runners_list_(std::make_shared<std::queue<RunnerInfo> >()) {
      runner_list_.emplace_back(runner_id_++, grid_, log_, new_runners_list_);
    }

    // Steps all runner instances
    // Returns false when all runners are dead
    // (woah that sounds dark)
    bool update();

  private:
    int runner_id_;
    std::shared_ptr<Logger> log_;
    std::shared_ptr<Grid> grid_;
    std::vector<Runner> runner_list_;

    std::shared_ptr<std::queue<RunnerInfo> > new_runners_list_;
  };
}

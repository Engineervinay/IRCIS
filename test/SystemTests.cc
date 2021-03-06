#include <gtest/gtest.h>
#include <Ircis.h>
#include <fstream>
#include <memory>
#include <sstream>

namespace Ircis {
  std::string getline(std::stringstream& os);

  class SystemTests : public ::testing::Test {
  protected:
    void SetUp() override {

    }

    // void TearDown() override {}

    std::shared_ptr<std::stringstream> output_ = std::make_shared<std::stringstream>();
    Ircis hello_world_{"hello_world.txt", output_, true};
    Ircis calc_{"calc.txt", output_, true};
    Ircis factors_{"factors.txt", output_, true};
    Ircis num2bin_{"num2bin.txt", output_, true};
  };

  TEST_F(SystemTests, HelloWorldOutput) {
    while (hello_world_.update());
    ASSERT_EQ("Hello World!", getline(*output_));
    output_->clear();
  }
  TEST_F(SystemTests, CalcOutput) {
    while (calc_.update());
    ASSERT_EQ("+=50", getline(*output_));
    ASSERT_EQ("-=10", getline(*output_));
    ASSERT_EQ("*=600", getline(*output_));
    ASSERT_EQ("/=1", getline(*output_));
    ASSERT_EQ("%=10", getline(*output_));
    ASSERT_EQ("20 30", getline(*output_));
    output_->clear();
  }
  TEST_F(SystemTests, FactorsOutput) {
    while (factors_.update());
    ASSERT_EQ(" 1 2 4 5 10 20 ", getline(*output_));
    output_->clear();
  }
  TEST_F(SystemTests, Num2BinOutput) {
    while (num2bin_.update());
    ASSERT_EQ("0111 ", getline(*output_));
    output_->clear();
  }
}

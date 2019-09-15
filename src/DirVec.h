#pragma once

#include <iostream>

namespace PTrain {
  enum Direction {
		  NORTH,
		  EAST,
		  WEST,
		  SOUTH
  };

  class DirVec {
  public:
    DirVec()
      : xx(0), yy(0), direction(Direction::EAST) { }

    DirVec(int start_x, int start_y, Direction start_dir)
      : xx(start_x), yy(start_y), direction(start_dir) { }

    void update();

    void set_position(int new_x, int new_y) {
      xx = new_x;
      yy = new_y;
    }
    void change_dir(Direction new_dir) { direction = new_dir; }
    Direction get_direction() const { return direction; }
    unsigned int get_x() const { return xx; }
    unsigned int get_y() const { return yy; }

    friend std::ostream& operator<<(std::ostream& os, const DirVec& pos);

  private:
    unsigned int xx, yy;
    Direction direction;
  };

  std::ostream& operator<<(std::ostream& os, const Direction& dir);
  std::ostream& operator<<(std::ostream& os, const DirVec& pos);
}

#pragma once

namespace cell
{
  template <typename T>
  class Base
  {
  private:
    T m_value;
    size_t m_row;
    size_t m_col;

  public:
    Base(val, r, c)
        : m_value(val), m_row(r), m_col(c) {}

    T value() { return m_value; }
    size_t row() { return m_row; }
    size_t col() { return m_col; }
  };
} // namespace cell

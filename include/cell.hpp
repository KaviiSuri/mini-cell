#pragma once

namespace cell
{
  template <typename T>
  class Base
  {
  private:
    T m_Value;
    size_t m_Row;
    size_t m_Col;

  public:
    Base(val, r, c)
        : m_Value(val), m_Row(r), m_Col(c) {}

    T value() { return m_Value; }
    size_t row() { return m_Row; }
    size_t col() { return m_Col; }
  };
} // namespace cell

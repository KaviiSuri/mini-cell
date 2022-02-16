#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace sv_lib
{
  class StringView
  {
  public:
    std::string *m_data;

  private:
    size_t m_start;
    size_t m_len;
    bool m_is_owner;

  public:
    // === constructors ===
    StringView(std::string *data)
        : m_data(data), m_start(0), m_len(data->length()), m_is_owner(false) {}

    StringView(std::string data)
        : m_start(0), m_len(data.length()), m_is_owner(true)
    {
      m_data = new std::string(data);
    }

    StringView(std::string *data, size_t start, size_t len)
        : m_data(data), m_start(start), m_len(len), m_is_owner(false) {}

    StringView(std::string data, size_t start, size_t len)
        : m_start(start), m_len(len), m_is_owner(true)
    {
      m_data = new std::string(data);
    }

    // === serialisation ==
    friend std::ostream &operator<<(std::ostream &os, StringView const &sv);

    // === methods ===
    bool is_owner() { return m_is_owner; }
    size_t length();
    char at(size_t i) const;
    char operator[](size_t i) const { return at(i); }

    std::vector<StringView> splitByDelim(char delim) const;

    std::string toString() const;
  };
} // namespace string_view_lib
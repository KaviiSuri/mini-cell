#pragma once
#include <string>
#include <iostream>
#include <vector>

class StringView
{
public:
  std::string *m_Data;

private:
  size_t m_Start;
  size_t m_Len;
  bool m_IsOwner;

public:
  // === constructors ===
  StringView(std::string *data)
      : m_Data(data), m_Start(0), m_Len(data->length()), m_IsOwner(false) {}

  StringView(std::string data)
      : m_Start(0), m_Len(data.length()), m_IsOwner(true)
  {
    m_Data = new std::string(data);
  }

  StringView(std::string *data, size_t start, size_t len)
      : m_Data(data), m_Start(start), m_Len(len), m_IsOwner(false) {}

  StringView(std::string data, size_t start, size_t len)
      : m_Start(start), m_Len(len), m_IsOwner(true)
  {
    m_Data = new std::string(data);
  }

  // === serialisation ==
  friend std::ostream &operator<<(std::ostream &os, StringView const &sv);

  // === methods ===
  bool is_owner() { return m_IsOwner; }
  size_t length();
  char at(size_t i) const;
  char operator[](size_t i) const { return at(i); }

  std::vector<StringView> split_by_delim(char delim) const;
};
#include "string_view.hpp"

std::ostream &operator<<(std::ostream &os, StringView const &sv)
{

  for (size_t i = 0; i < sv.m_Len; i++)
    os << sv[i];

  return os;
}

char StringView::at(size_t i) const
{
  return m_Data->at(i + m_Start);
}

std::vector<StringView> StringView::split_by_delim(char delim) const
{
  std::vector<StringView> result;

  size_t next_start = 0;
  for (size_t idx = 0; idx < m_Len; idx++)
  {
    if (at(idx) == delim)
    {
      result.push_back(StringView(m_Data, next_start, idx - next_start));
      next_start = idx + 1;
    }
  }
  result.push_back(StringView(m_Data, next_start, m_Len - next_start));

  return result;
}

std::string StringView::to_string() const
{
  std::string result;
  result.reserve(m_Len);
  for (int idx = 0; idx < m_Len; idx++)
    result.push_back(at(idx));

  return result;
}
#include "sv_lib/string_view.hpp"

namespace sv_lib
{
  std::ostream &operator<<(std::ostream &os, StringView const &sv)
  {

    for (size_t i = 0; i < sv.m_len; i++)
      os << sv[i];

    return os;
  }

  char StringView::at(size_t i) const
  {
    return m_data->at(i + m_start);
  }

  std::vector<StringView> StringView::splitByDelim(char delim) const
  {
    std::vector<StringView> result;

    size_t next_start = 0;
    for (size_t idx = 0; idx < m_len; idx++)
    {
      if (at(idx) == delim)
      {
        result.push_back(StringView(m_data, next_start, idx - next_start));
        next_start = idx + 1;
      }
    }
    result.push_back(StringView(m_data, next_start, m_len - next_start));

    return result;
  }

  std::string StringView::toString() const
  {
    std::string result;
    result.reserve(m_len);
    for (size_t idx = 0; idx < m_len; idx++)
      result.push_back(at(idx));

    return result;
  }
} // namespace sv_lib
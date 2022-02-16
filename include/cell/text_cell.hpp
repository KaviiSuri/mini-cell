#pragma once
#include "cell.hpp"
#include "string_view.hpp"

namespace cell
{
  class Text : Base<sv_lib::StringView>
  {
  };
}
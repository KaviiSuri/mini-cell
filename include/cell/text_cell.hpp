#pragma once
#include "cell.hpp"
#include "string_view.hpp"

namespace minicell::cell
{
  class Text : Base<sv_lib::StringView>
  {
  };
}
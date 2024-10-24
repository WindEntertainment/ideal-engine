#pragma once
#include <editor/editor.hpp>
#include <utils/utils.hpp>
#include <editor/shared/tab-bar/tab.hpp>

namespace editor {
  namespace components {
    class TabBar {
    public:
      TabBar(Tabs tabs);
      void render();

    private:
      Tabs tabs = {};
    };
  } // namespace components
} // namespace editor

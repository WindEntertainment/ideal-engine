#include <editor/shared/tab-bar/tab-bar.hpp>

namespace editor {
  namespace components {
    TabBar::TabBar(Tabs tabs) : tabs(tabs) {}

    void TabBar::render() {
      for (auto tab : tabs) {
        tab.render();
      }
    }
  } // namespace components
} // namespace editor

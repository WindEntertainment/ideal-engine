#include <editor/shared/tab-bar/tab-item.hpp>

namespace editor {
  namespace components {
    TabItem::TabItem(const std::string id, Callback callback, bool isOpen)
        : id(id), callback(callback), isOpen(isOpen) {}

    void TabItem::render() {
      if (ImGui::BeginTabItem(id.c_str(), &isOpen)) {
        callback();
        ImGui::EndTabItem();
      }
    }
  } // namespace components
} // namespace editor

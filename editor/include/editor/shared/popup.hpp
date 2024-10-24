#pragma once
#include <editor/editor.hpp>
#include <utils/utils.hpp>

namespace editor {
  namespace components {
    class Popup {
    public:
      const std::string id;
      Popup(const std::string id, Callback callback, bool isOpen = false);
      void render();
      void open();
      void close();
      void toggle();

    private:
      bool isOpen = false;
      Callback callback;
    };
  } // namespace components
} // namespace editor

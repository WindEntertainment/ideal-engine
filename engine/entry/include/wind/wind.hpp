#include <wind/window/window.hpp>

namespace wind {
    class Engine {
    public:
        static int run();
        static std::shared_ptr<Window> getMainWindow();
    private:
        static std::shared_ptr<Window> _mainWindow;
    };
}
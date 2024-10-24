#include "input-system/trigger.hpp"
#include "input-system/keys.hpp"
#include "utils/includes.hpp"

namespace wind {
  Trigger::Trigger(
    std::string name,
    const Keys bindings,
    const Callbacks callbacks
  )
      : name(name), bindings(bindings), callbacks(callbacks) {}

} // namespace wind

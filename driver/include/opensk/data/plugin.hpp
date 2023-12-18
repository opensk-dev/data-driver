//
// Created by asuka on 02.07.2023.
//

#ifndef SK_DATA_PLUGIN_HPP
#define SK_DATA_PLUGIN_HPP

namespace sk::data {

class Plugin {
  public:
    Plugin() = default;
    ~Plugin() = default;

    Plugin(const Plugin&) = default;
    Plugin& operator=(const Plugin&) = default;

    Plugin(Plugin&&) noexcept = default;
    Plugin& operator=(Plugin&&) noexcept = default;
};

}// namespace sk::data

#endif// SK_DATA_PLUGIN_HPP

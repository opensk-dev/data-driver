//
// Created by asuka on 02.07.2023.
//

#ifndef SK_DATA_PLUGIN_SOURCE_HPP
#define SK_DATA_PLUGIN_SOURCE_HPP

namespace sk::data {

template<class PluginSourceType>
concept PluginSource = requires(PluginSourceType plugin_source) {
};

}// namespace sk::data

#endif// SK_DATA_PLUGIN_SOURCE_HPP

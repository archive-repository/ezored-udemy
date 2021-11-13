// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include <functional>

namespace ezored { namespace net { namespace http {

enum class HttpMethod : int {
    METHOD_GET,
    METHOD_POST,
    METHOD_HEAD,
    METHOD_PUT,
    METHOD_DELETE,
    METHOD_PATCH,
    METHOD_CONNECT,
    METHOD_OPTIONS,
    METHOD_TRACE,
};

} } }  // namespace ezored::net::http

namespace std {

template <>
struct hash<::ezored::net::http::HttpMethod> {
    size_t operator()(::ezored::net::http::HttpMethod type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std

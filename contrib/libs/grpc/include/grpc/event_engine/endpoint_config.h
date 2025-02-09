// Copyright 2021 The gRPC Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef GRPC_EVENT_ENGINE_ENDPOINT_CONFIG_H
#define GRPC_EVENT_ENGINE_ENDPOINT_CONFIG_H

#include <grpc/support/port_platform.h>

#include <util/generic/string.h>
#include <util/string/cast.h>

#include "y_absl/strings/string_view.h"
#include "y_absl/types/variant.h"

namespace grpc_event_engine {
namespace experimental {

/// Collection of parameters used to configure client and server endpoints. The
/// \a EndpointConfig maps string-valued keys to values of type int,
/// string_view, or void pointer. Each EventEngine implementation should
/// document its set of supported configuration options.
class EndpointConfig {
 public:
  virtual ~EndpointConfig() = default;
  using Setting = y_absl::variant<y_absl::monostate, int, y_absl::string_view, void*>;
  /// Returns the Setting for a specified key, or \a y_absl::monostate if there is
  /// no such entry. Caller does not take ownership of the resulting value.
  virtual Setting Get(y_absl::string_view key) const = 0;
};

}  // namespace experimental
}  // namespace grpc_event_engine

#endif  // GRPC_EVENT_ENGINE_ENDPOINT_CONFIG_H

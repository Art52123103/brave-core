/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_NET_SYSTEM_REQUEST_HANDLER_H_
#define BRAVE_NET_SYSTEM_REQUEST_HANDLER_H_

#include <memory>

#include "base/callback.h"
#include "net/base/net_export.h"

namespace network {
struct ResourceRequest;
}  // network

namespace base {
template <typename T>
struct DefaultSingletonTraits;
}  // namespace base

namespace net {

class NET_EXPORT SystemRequestHandler {
 public:
  typedef base::Callback<std::shared_ptr<network::ResourceRequest>
      (std::shared_ptr<network::ResourceRequest>)>
      OnBeforeSystemRequestCallback;

  // Returns the instance of SystemRequestHandler.
  static SystemRequestHandler* GetInstance();

  // Registers callback to be invoked in different layers.
  void RegisterOnBeforeSystemRequestCallback(
      const OnBeforeSystemRequestCallback& cb);

  std::shared_ptr<network::ResourceRequest> OnBeforeSystemRequest(
      std::shared_ptr<network::ResourceRequest> url_request);

 private:
  friend struct base::DefaultSingletonTraits<SystemRequestHandler>;

  SystemRequestHandler();
  ~SystemRequestHandler();

  OnBeforeSystemRequestCallback on_before_system_request_callback_;

  DISALLOW_COPY_AND_ASSIGN(SystemRequestHandler);
};

}  // namespace net

#endif  // BRAVE_NET_SYSTEM_REQUEST_HANDLER_H_

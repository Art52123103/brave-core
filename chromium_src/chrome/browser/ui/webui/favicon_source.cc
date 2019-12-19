// Copyright (c) 2019 The Brave Authors
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "build/build_config.h"

#if defined(OS_ANDROID)
#define IDR_DEFAULT_FAVICON_32 IDR_DEFAULT_FAVICON
#define IDR_DEFAULT_FAVICON_64 IDR_DEFAULT_FAVICON
#define IDR_DEFAULT_FAVICON_DARK_32 IDR_DEFAULT_FAVICON_DARK
#define IDR_DEFAULT_FAVICON_DARK_64 IDR_DEFAULT_FAVICON_DARK
#endif

#include "../../../../../chrome/browser/ui/webui/favicon_source.cc"  // NOLINT

#if defined(OS_ANDROID)
#undef IDR_DEFAULT_FAVICON_32
#undef IDR_DEFAULT_FAVICON_64
#undef IDR_DEFAULT_FAVICON_DARK_32
#undef IDR_DEFAULT_FAVICON_DARK_64
#endif

load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
  name = "hiredis",
  include_prefix = "hiredis",
  hdrs = [
      "alloc.h",
      "async.h",
      "hiredis.h",
      "read.h",
      "sds.h",
  ] + glob(["adapters/*.h"]),
  textual_hdrs = ["dict.c"],
#   srcs = [
#     "lib/libhiredis.a",
#     "lib/libhiredis.dylib",
#   ],
  srcs = [
      "net.c",
      "hiredis.c",
      "sds.c",
      "async.c",
      "read.c",
      "sockcompat.c",
      "alloc.c",
  ] + glob(["*.h"]),
#   copts = ["-I.", "-Wunused-function"],
  includes = [
    ".",
  ],
  visibility = ["//visibility:public"],
)

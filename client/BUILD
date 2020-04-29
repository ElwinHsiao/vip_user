load("@rules_cc//cc:defs.bzl", "cc_binary")


cc_library(
  name = "lib",
#   strip_include_prefix = "common",
  hdrs = glob(["*.h"]),
  srcs = glob(["*.cc"]),
  deps = [
      "@com_github_grpc_grpc//:grpc++_reflection",
      "//protos:vipuser_proto",
  ],

  visibility = ["//visibility:public"],
)

cc_binary(
    name = "vipuser_client",
    srcs = [
        "client_main.cc",
    ],
    deps = [
        ":lib",
    ],
)
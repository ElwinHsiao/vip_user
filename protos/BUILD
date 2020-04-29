# load(':grpc_proto.bzl', 'proto_library')



# proto_library(
#     name = 'vipuser_proto',
#     src = 'vipuser.proto',
#     has_service = True,
# )


load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
  name = "vipuser_proto",
  hdrs = glob(["*.h"]),
  srcs = glob(["*.cc"]),
  deps = [
      "@com_github_grpc_grpc//:grpc++_reflection",
  ],

  visibility = ["//visibility:public"],
)
load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "hello",
    srcs = ["greeter_server.cc"],
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)

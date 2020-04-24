load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "hello",
    srcs = [
        "greeter_server.cc",
        "helloworld.pb.cc",
        "helloworld.grpc.pb.cc",
        "helloworld.grpc.pb.h",
        "helloworld.pb.h",
    ],
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)

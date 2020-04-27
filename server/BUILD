load("@rules_cc//cc:defs.bzl", "cc_binary")

# cc_import(                             
#     name = "hiredis",
#     hdrs = glob(["../redis-5.0.8/deps/hiredis/*.h"]),
#     shared_library = "../redis-5.0.8/deps/libhiredis.dylib",
# )


cc_binary(
    name = "greeting_server",
    srcs = [
        "greeter_server.cc",
        "helloworld.pb.cc",
        "helloworld.grpc.pb.cc",
        "helloworld.grpc.pb.h",
        "helloworld.pb.h",
        "dbhelper.cc",
        "dbhelper.h",
    ],
    # copts = ["-I/usr/local/include"],
    # linkopts = ["-lhiredis"],
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@usr_local//:hiredis",
        # "@usr_local//:libs",
        # ":hiredis"
    ],
    # linkstatic = 1,
)


cc_binary(
    name = "vipuserserver",
    srcs = [
        "server_main.cc",
        "vipuser_server.cc",
        "vipuser_server.h",
        "dbhelper.cc",
        "dbhelper.h",
    ],
    # includes = [
    #     "third_party/boost_uuid/include"
    # ],
    # copts = ["-Ithird_party/boost_uuid/include"],
    # linkopts = ["-lhiredis"],
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@usr_local//:hiredis",
        "@boost_uuid//:boost_uuid",
        # ":hiredis"
    ],
    # linkstatic = 1,
)

load("@rules_cc//cc:defs.bzl", "cc_binary")


cc_library(
  name = "common",
  strip_include_prefix = "common",
  hdrs = glob(["common/*.h"]),
  srcs = glob(["common/*.cc"]),
  deps = [
      "@boost//:uuid",
      "@com_github_grpc_grpc//:grpc++_reflection",
  ],

  visibility = ["//visibility:public"],
)

cc_library(
    name = "account_service",
    strip_include_prefix = "account_service",
    hdrs = glob(["account_service/*.h"]),
    srcs = glob(["account_service/*.cc"]),
    deps = [
        "@hiredis//:hiredis",
        ":common",
        ":libpqxx",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "access_service",
    strip_include_prefix = "access_service",
    hdrs = glob(["access_service/*.h"]),
    srcs = glob(["access_service/*.cc"]),
    deps = [
        ":common",
    ],
)

cc_binary(
    name = "vipuserserver",
    srcs = [
        "server_main.cc",
    ],
    deps = [
        # "@com_github_grpc_grpc//:grpc++_reflection",
        ":account_service",
    ],
)



load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")
cmake_external(
   name = "libpqxx",
   lib_name = "libpqxx",
   lib_source = "@libpqxx//:all",
#    out_lib_dir = "src",
   #static_libraries = ["libpqxx-7.0.a"],
   shared_libraries = ["libpqxx.dylib"],
)

# load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")
# configure_make(
#     name = "libpqxx",
#     lib_source = "@libpqxx//:all",
#     #static_libraries = ["libpqxx.a"],
# )





cc_binary(
    name = "vipuserserver2",
    srcs = [
        "server_main.cc",
        "vipuser_server.cc",
        "vipuser_server.h",
        "redis_helper.cc",
        "redis_helper.h",
        "crypt_helper.cc",
        "crypt_helper.h",
        "crypt_plus.cc",
        "crypt_plus.h",
        "psql_helper.cc",
        "psql_helper.h",
        "vipuser_common.cc",
        "vipuser_common.h",
    ],
    # includes = [
    #     "third_party/boost_uuid/include"
    # ],
    # copts = ["-Ithird_party/boost_uuid/include"],
    # linkopts = ["-lhiredis"],
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        # "@usr_local//:hiredis",
        "@hiredis//:hiredis",
        "@boost//:uuid",
        ":libpqxx",
        # "@picosha2//:picosha2"
        # "@boost_uuid//:boost_uuid",
        # ":hiredis"
    ],
    # linkstatic = False,
)


cc_binary(
    name = "greeting_server",
    srcs = [
        "greeter_server.cc",
        "helloworld.pb.cc",
        "helloworld.grpc.pb.cc",
        "helloworld.grpc.pb.h",
        "helloworld.pb.h",
        "redis_helper.cc",
        "redis_helper.h",
    ],
    # copts = ["-I/usr/local/include"],
    # linkopts = ["-lhiredis"],
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        # "@usr_local//:hiredis",
        # "@usr_local//:libs",
        # ":hiredis"
    ],
    # linkstatic = 1,
)

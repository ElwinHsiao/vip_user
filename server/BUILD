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

load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")


cmake_external(
   name = "libpgxx",
   lib_name = "libpgxx",
   # Values to be passed as -Dkey=value on the CMake command line;
   # here are serving to provide some CMake script configuration options
   cache_entries = {
       "NOFORTRAN": "on",
       "BUILD_WITHOUT_LAPACK": "no",
   },
   lib_source = "@libpgxx//:all",

   # We are selecting the resulting static library to be passed in C/C++ provider
   # as the result of the build;
   # However, the cmake_external dependants could use other artefacts provided by the build,
   # according to their CMake script
   static_libraries = ["libpqxx-7.0.a"],
)

cc_binary(
    name = "vipuserserver",
    srcs = [
        "server_main.cc",
        "vipuser_server.cc",
        "vipuser_server.h",
        "redis_helper.cc",
        "redis_helper.h",
        "crypt_helper.cc",
        "crypt_helper.h",
        "crypt_plus.cc",
        "crypt_plus.h"
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
        ":libpgxx",
        # "@picosha2//:picosha2"
        # "@boost_uuid//:boost_uuid",
        # ":hiredis"
    ],
    # linkstatic = 1,
)


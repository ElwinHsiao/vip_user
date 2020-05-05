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
        ":common",
        ":libpqxx",
        ":libpq",
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
        "@hiredis//:hiredis",
    ],
)

cc_binary(
    name = "vipuserserver",
    srcs = [
        "server_main.cc",
        "vipuser_server.cc",
        "vipuser_server.h",
    ],
    deps = [
        # "@com_github_grpc_grpc//:grpc++_reflection",
        ":account_service",
        ":access_service",
        "//protos:vipuser_proto",
    ],
)



#load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")
#cmake_external(
#   name = "libpqxx",
#   lib_name = "libpqxx",
#   lib_source = "@libpqxx//:all",
#   cmake_options = [
#   #     "-DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql"
#   #    "-DCMAKE_CXX_FLAGS=-std=c++11",
#   #    "-DCMAKE_TOOLCHAIN_FILE=/home/elwinxiao/work/vip_user/linux.toolchain.cmake"
#   #    "-DCMAKE_C_COMPILER=/usr/bin/clang", 
#   #    "-DCMAKE_CXX_COMPILER=/usr/bin/clang++",
#   ],
#   env_vars = {
#   #    "CXXFLAG": "-std=c++11"
#   #    "CC": "/opt/rh/devtoolset-7/root/usr/bin/gcc",
#   #    "CXX": "/opt/rh/devtoolset-7/root/usr/bin/g++",
#   },
#   #cmake_options = ["CMAKE_CXX_FLAGS -std=c++11"],
##   env_vars = {"CMAKE_CXX_FLAGS": "-std=gnu++11"},
#    out_lib_dir = "src",
##    static_libraries = ["libpqxx.a"],
##   shared_libraries = ["libpqxx.dylib"],
#)

load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")
configure_make(
    name = "libpqxx",
    lib_source = "@libpqxx//:all",
    configure_options = [
        "--disable-documentation",
    ],
    #configure_env_vars = {
    #    "C_FLAGS": "-Wall -std=c++11",
    #    "CXXFLAG": "-Wall",
    #    "CC": "/usr/bin/clang",
    #    "CXX": "/usr/bin/clang++",
    #    "AR": "/usr/bin/llvm-ar",
    #    "LINKER": "/usr/bin/llvm-ld",
    #    "NM": "/usr/bin/llvm-nm",
    #    "OBJDUMP": "/usr/bin/llvm-objdump",
    #    "RANLIB": "/usr/bin/llvm-ranlib",
    #},
    #static_libraries = ["libpqxx.a"],
    #shared_libraries = ["libaprutil-1.so"],
)

configure_make(
    name = "libpq",
    lib_source = "@libpq//:all",
    configure_options = [
        "--disable-documentation",
    ],
    #configure_env_vars = {
    #    "C_FLAGS": "-Wall -std=c++11",
    #    "CXXFLAG": "-Wall",
    #    "CC": "/usr/bin/clang",
    #    "CXX": "/usr/bin/clang++",
    #    "AR": "/usr/bin/llvm-ar",
    #    "LINKER": "/usr/bin/llvm-ld",
    #    "NM": "/usr/bin/llvm-nm",
    #    "OBJDUMP": "/usr/bin/llvm-objdump",
    #    "RANLIB": "/usr/bin/llvm-ranlib",
    #},
    static_libraries = ["libpq.a", "libpgport.a"],
    #shared_libraries = ["libaprutil-1.so"],
)

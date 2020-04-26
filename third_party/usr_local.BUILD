load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
  name = "headers",
  strip_include_prefix = "include",
  hdrs = glob(["include/hiredis/**"]),
  srcs = [
    "lib/libhiredis.a",
    "lib/libhiredis.dylib",
  ],
#   srcs = glob(['include/hiredis/**/*.h']),
#   includes = [
#     "include/hiredis",
#   ],
  visibility = ["//visibility:public"],
)

# cc_library(
#   name = "libs",
#   srcs = [
#     "libhiredis.a",
#     "libhiredis.dylib",
#   ],
#   visibility = ["//visibility:public"],
# )
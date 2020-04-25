load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/cb81fe0dfaa424eb50de26fb7c904a27a78c3f76.tar.gz",
    ],
    strip_prefix = "grpc-cb81fe0dfaa424eb50de26fb7c904a27a78c3f76",
)


load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()


new_local_repository(
  name = "usr_local_include",
  path = "/usr/local/include",
  build_file = "third_party/usr_local.BUILD",
)

new_local_repository(
  name = "usr_local_lib",
  path = "/usr/local/lib",
  build_file = "third_party/usr_local_lib.BUILD",
)
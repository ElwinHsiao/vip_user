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
  name = "usr_local",
  path = "/usr/local",
  build_file = "third_party/usr_local.BUILD",
)

# new_local_repository(
#   name = "usr_local_lib",
#   path = "/usr/local/lib",
#   build_file = "third_party/usr_local_lib.BUILD",
# )

# new_local_repository(
#   name = "boost_uuid",
#   path = "third_party/boost",
#   build_file = "third_party/boost_uuid.BUILD"
# )


load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "9f9fb8b2f0213989247c9d5c0e814a8451d18d7f",
    remote = "https://github.com/nelhage/rules_boost",
    shallow_since = "1570056263 -0700",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()
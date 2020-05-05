#!/bin/sh

base_dir=$(cd "`dirname "$0"`" && pwd)
cp -f $base_dir/../../bazel-bin/server/vipuserserver ./
cp -rf $base_dir/../../keys ./
sudo docker build -t vipuser:test .
FROM ubuntu:16:04

WORKDIR /root

COPY sources.list ./
RUN mv -f ./sources.list /etc/apt/

RUN apt-get update && apt-get install -y build-essential

COPY bazel-3.1.0-installer-linux-x86_64.sh ./
RUN chmod +x bazel-3.1.0-installer-linux-x86_64.sh && ./bazel-3.1.0-installer-linux-x86_64.sh --user && echo "export PATH=\$PATH:\$HOME/bin" >> ~/.bashrc

# RUN cd /src && bazel build //server:vipuserserver

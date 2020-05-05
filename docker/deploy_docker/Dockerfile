FROM alpine

WORKDIR /root

COPY bazel-bin/server/vipuserserver ./
COPY keys ./
ENV VIP_USER_SEVER_KEY=/root/keys/server.key
ENV VIP_USER_SEVER_CRT=/root/keys/server.crt

RUN createdb -O postgres vipuser

RUN mkdir /data > /dev/null
VOLUME /data

CMD ["bash"]
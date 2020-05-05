FROM ubuntu:20.04

WORKDIR /root

COPY ./vipuserserver ./keys ./
ENV VIP_USER_SEVER_KEY=/root/keys/server.key VIP_USER_SEVER_CRT=/root/keys/server.crt

# RUN createdb -O postgres vipuser

RUN mkdir /data > /dev/null
VOLUME /data

CMD ["./vipuserserver"]
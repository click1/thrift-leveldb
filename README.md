##简单的学习thrift 和 leveldb

    生成框架:
    thrift --gen cpp level.thrift
    thrift --gen php level.thrift

    编译服务端:
    cd gen-cpp
    g++ *.cpp -o level_server -lthrift -lleveldb
    ./level_server

    运行客户端
    cd gen-php
    php client.php



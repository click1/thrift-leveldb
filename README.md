##简单的学习thrift 和 leveldb

    thrift --gen cpp level.thrift
    thrift --gen php level.thrift

    cd gen-cpp
    g++ *.cpp -o level_server -lthrift -lleveldb
    ./level_server

    cd gen-php
    php client.php



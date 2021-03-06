#!/usr/bin/env php
<?php


error_reporting(E_ALL);

require_once __DIR__ . "/Leveldb.php";
require_once __DIR__ .'/../../lib/php/lib/Thrift/ClassLoader/ThriftClassLoader.php';

use Thrift\ClassLoader\ThriftClassLoader;

$GEN_DIR = realpath(dirname(__FILE__).'/..').'/gen-php';

$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift',  __DIR__ . '/../../lib/php/lib');
$loader->registerDefinition('shared', $GEN_DIR);
$loader->registerDefinition('tutorial', $GEN_DIR);
$loader->register();

/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

use Thrift\Protocol\TBinaryProtocol;
use Thrift\Transport\TSocket;
use Thrift\Transport\THttpClient;
use Thrift\Transport\TBufferedTransport;
use Thrift\Exception\TException;

try {
  if (array_search('--http', $argv)) {
    $socket = new THttpClient('localhost', 8080, '/php/PhpServer.php');
  } else {
    $socket = new TSocket('localhost', 9090);
  }
  $transport = new TBufferedTransport($socket, 1024, 1024);
  $protocol = new TBinaryProtocol($transport);
  $client = new LeveldbClient($protocol);

  $transport->open();

  $client->Open("/tmp/hongcha_db");
 // $client->Set('hongcha', '测试');
  echo $client->Get('hongcha') . "\n";
  $client->Close(); 

  echo $client->Get('hongcha') . "\n";
  $transport->close();

} catch (TException $tx) {
  print 'TException: '.$tx->getMessage()."\n";
}

?>

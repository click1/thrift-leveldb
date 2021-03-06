// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Leveldb.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <leveldb/db.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::LevelDB;

class LeveldbHandler : virtual public LeveldbIf {
 private:
     leveldb::DB *db;
     leveldb::Options options;
     leveldb::Status status;
 public:
  LeveldbHandler() {
    // Your initialization goes here
  }

  void Get(std::string& _return, const std::string& key) {
    // Your implementation goes here
    if(NULL == db){
        _return = "FALSE";
        return;
    }
    status = db->Get(leveldb::ReadOptions(), key, &_return);
    printf("Get\n");
    if(! status.ok()){
        _return = "FALSE";
    }
  }

  bool Set(const std::string& key, const std::string& value) {
    // Your implementation goes here
    if(NULL == db){
        return false;
    }
    status = db->Put(leveldb::WriteOptions(), key, value);
    printf("Set\n");
    return status.ok();
  }

  bool Open(const std::string& filename) {
    // Your implementation goes here
    // 打开数据库
    options.create_if_missing = true;
    status = leveldb::DB::Open(options, filename, &db);
    printf("Open\n");
    return status.ok();
  }

  bool Close() {
    // Your implementation goes here
    //关闭数据库
    delete db;
    db = NULL;
    printf("Close\n");
    return true;
  }

  bool Delete(const std::string& key) {
    // Your implementation goes here
    printf("Delete\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<LeveldbHandler> handler(new LeveldbHandler());
  shared_ptr<TProcessor> processor(new LeveldbProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}


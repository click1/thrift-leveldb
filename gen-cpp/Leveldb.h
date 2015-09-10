/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Leveldb_H
#define Leveldb_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "leveldb_types.h"

namespace LevelDB {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class LeveldbIf {
 public:
  virtual ~LeveldbIf() {}
  virtual void Get(std::string& _return, const std::string& key) = 0;
  virtual bool Set(const std::string& key, const std::string& value) = 0;
  virtual bool Open(const std::string& filename) = 0;
  virtual bool Close() = 0;
  virtual bool Delete(const std::string& key) = 0;
};

class LeveldbIfFactory {
 public:
  typedef LeveldbIf Handler;

  virtual ~LeveldbIfFactory() {}

  virtual LeveldbIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(LeveldbIf* /* handler */) = 0;
};

class LeveldbIfSingletonFactory : virtual public LeveldbIfFactory {
 public:
  LeveldbIfSingletonFactory(const boost::shared_ptr<LeveldbIf>& iface) : iface_(iface) {}
  virtual ~LeveldbIfSingletonFactory() {}

  virtual LeveldbIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(LeveldbIf* /* handler */) {}

 protected:
  boost::shared_ptr<LeveldbIf> iface_;
};

class LeveldbNull : virtual public LeveldbIf {
 public:
  virtual ~LeveldbNull() {}
  void Get(std::string& /* _return */, const std::string& /* key */) {
    return;
  }
  bool Set(const std::string& /* key */, const std::string& /* value */) {
    bool _return = false;
    return _return;
  }
  bool Open(const std::string& /* filename */) {
    bool _return = false;
    return _return;
  }
  bool Close() {
    bool _return = false;
    return _return;
  }
  bool Delete(const std::string& /* key */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _Leveldb_Get_args__isset {
  _Leveldb_Get_args__isset() : key(false) {}
  bool key :1;
} _Leveldb_Get_args__isset;

class Leveldb_Get_args {
 public:

  Leveldb_Get_args(const Leveldb_Get_args&);
  Leveldb_Get_args& operator=(const Leveldb_Get_args&);
  Leveldb_Get_args() : key() {
  }

  virtual ~Leveldb_Get_args() throw();
  std::string key;

  _Leveldb_Get_args__isset __isset;

  void __set_key(const std::string& val);

  bool operator == (const Leveldb_Get_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Get_args& obj);

};


class Leveldb_Get_pargs {
 public:


  virtual ~Leveldb_Get_pargs() throw();
  const std::string* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Get_pargs& obj);

};

typedef struct _Leveldb_Get_result__isset {
  _Leveldb_Get_result__isset() : success(false) {}
  bool success :1;
} _Leveldb_Get_result__isset;

class Leveldb_Get_result {
 public:

  Leveldb_Get_result(const Leveldb_Get_result&);
  Leveldb_Get_result& operator=(const Leveldb_Get_result&);
  Leveldb_Get_result() : success() {
  }

  virtual ~Leveldb_Get_result() throw();
  std::string success;

  _Leveldb_Get_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Leveldb_Get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Get_result& obj);

};

typedef struct _Leveldb_Get_presult__isset {
  _Leveldb_Get_presult__isset() : success(false) {}
  bool success :1;
} _Leveldb_Get_presult__isset;

class Leveldb_Get_presult {
 public:


  virtual ~Leveldb_Get_presult() throw();
  std::string* success;

  _Leveldb_Get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Get_presult& obj);

};

typedef struct _Leveldb_Set_args__isset {
  _Leveldb_Set_args__isset() : key(false), value(false) {}
  bool key :1;
  bool value :1;
} _Leveldb_Set_args__isset;

class Leveldb_Set_args {
 public:

  Leveldb_Set_args(const Leveldb_Set_args&);
  Leveldb_Set_args& operator=(const Leveldb_Set_args&);
  Leveldb_Set_args() : key(), value() {
  }

  virtual ~Leveldb_Set_args() throw();
  std::string key;
  std::string value;

  _Leveldb_Set_args__isset __isset;

  void __set_key(const std::string& val);

  void __set_value(const std::string& val);

  bool operator == (const Leveldb_Set_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Set_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Set_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Set_args& obj);

};


class Leveldb_Set_pargs {
 public:


  virtual ~Leveldb_Set_pargs() throw();
  const std::string* key;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Set_pargs& obj);

};

typedef struct _Leveldb_Set_result__isset {
  _Leveldb_Set_result__isset() : success(false) {}
  bool success :1;
} _Leveldb_Set_result__isset;

class Leveldb_Set_result {
 public:

  Leveldb_Set_result(const Leveldb_Set_result&);
  Leveldb_Set_result& operator=(const Leveldb_Set_result&);
  Leveldb_Set_result() : success(0) {
  }

  virtual ~Leveldb_Set_result() throw();
  bool success;

  _Leveldb_Set_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const Leveldb_Set_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Set_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Set_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Set_result& obj);

};

typedef struct _Leveldb_Set_presult__isset {
  _Leveldb_Set_presult__isset() : success(false) {}
  bool success :1;
} _Leveldb_Set_presult__isset;

class Leveldb_Set_presult {
 public:


  virtual ~Leveldb_Set_presult() throw();
  bool* success;

  _Leveldb_Set_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Set_presult& obj);

};

typedef struct _Leveldb_Open_args__isset {
  _Leveldb_Open_args__isset() : filename(false) {}
  bool filename :1;
} _Leveldb_Open_args__isset;

class Leveldb_Open_args {
 public:

  Leveldb_Open_args(const Leveldb_Open_args&);
  Leveldb_Open_args& operator=(const Leveldb_Open_args&);
  Leveldb_Open_args() : filename() {
  }

  virtual ~Leveldb_Open_args() throw();
  std::string filename;

  _Leveldb_Open_args__isset __isset;

  void __set_filename(const std::string& val);

  bool operator == (const Leveldb_Open_args & rhs) const
  {
    if (!(filename == rhs.filename))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Open_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Open_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Open_args& obj);

};


class Leveldb_Open_pargs {
 public:


  virtual ~Leveldb_Open_pargs() throw();
  const std::string* filename;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Open_pargs& obj);

};

typedef struct _Leveldb_Open_result__isset {
  _Leveldb_Open_result__isset() : success(false) {}
  bool success :1;
} _Leveldb_Open_result__isset;

class Leveldb_Open_result {
 public:

  Leveldb_Open_result(const Leveldb_Open_result&);
  Leveldb_Open_result& operator=(const Leveldb_Open_result&);
  Leveldb_Open_result() : success(0) {
  }

  virtual ~Leveldb_Open_result() throw();
  bool success;

  _Leveldb_Open_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const Leveldb_Open_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Open_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Open_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Open_result& obj);

};

typedef struct _Leveldb_Open_presult__isset {
  _Leveldb_Open_presult__isset() : success(false) {}
  bool success :1;
} _Leveldb_Open_presult__isset;

class Leveldb_Open_presult {
 public:


  virtual ~Leveldb_Open_presult() throw();
  bool* success;

  _Leveldb_Open_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Open_presult& obj);

};


class Leveldb_Close_args {
 public:

  Leveldb_Close_args(const Leveldb_Close_args&);
  Leveldb_Close_args& operator=(const Leveldb_Close_args&);
  Leveldb_Close_args() {
  }

  virtual ~Leveldb_Close_args() throw();

  bool operator == (const Leveldb_Close_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Leveldb_Close_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Close_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Close_args& obj);

};


class Leveldb_Close_pargs {
 public:


  virtual ~Leveldb_Close_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Close_pargs& obj);

};

typedef struct _Leveldb_Close_result__isset {
  _Leveldb_Close_result__isset() : success(false) {}
  bool success :1;
} _Leveldb_Close_result__isset;

class Leveldb_Close_result {
 public:

  Leveldb_Close_result(const Leveldb_Close_result&);
  Leveldb_Close_result& operator=(const Leveldb_Close_result&);
  Leveldb_Close_result() : success(0) {
  }

  virtual ~Leveldb_Close_result() throw();
  bool success;

  _Leveldb_Close_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const Leveldb_Close_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Close_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Close_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Close_result& obj);

};

typedef struct _Leveldb_Close_presult__isset {
  _Leveldb_Close_presult__isset() : success(false) {}
  bool success :1;
} _Leveldb_Close_presult__isset;

class Leveldb_Close_presult {
 public:


  virtual ~Leveldb_Close_presult() throw();
  bool* success;

  _Leveldb_Close_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Close_presult& obj);

};

typedef struct _Leveldb_Delete_args__isset {
  _Leveldb_Delete_args__isset() : key(false) {}
  bool key :1;
} _Leveldb_Delete_args__isset;

class Leveldb_Delete_args {
 public:

  Leveldb_Delete_args(const Leveldb_Delete_args&);
  Leveldb_Delete_args& operator=(const Leveldb_Delete_args&);
  Leveldb_Delete_args() : key() {
  }

  virtual ~Leveldb_Delete_args() throw();
  std::string key;

  _Leveldb_Delete_args__isset __isset;

  void __set_key(const std::string& val);

  bool operator == (const Leveldb_Delete_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Delete_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Delete_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Delete_args& obj);

};


class Leveldb_Delete_pargs {
 public:


  virtual ~Leveldb_Delete_pargs() throw();
  const std::string* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Delete_pargs& obj);

};

typedef struct _Leveldb_Delete_result__isset {
  _Leveldb_Delete_result__isset() : success(false) {}
  bool success :1;
} _Leveldb_Delete_result__isset;

class Leveldb_Delete_result {
 public:

  Leveldb_Delete_result(const Leveldb_Delete_result&);
  Leveldb_Delete_result& operator=(const Leveldb_Delete_result&);
  Leveldb_Delete_result() : success(0) {
  }

  virtual ~Leveldb_Delete_result() throw();
  bool success;

  _Leveldb_Delete_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const Leveldb_Delete_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Leveldb_Delete_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Leveldb_Delete_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Delete_result& obj);

};

typedef struct _Leveldb_Delete_presult__isset {
  _Leveldb_Delete_presult__isset() : success(false) {}
  bool success :1;
} _Leveldb_Delete_presult__isset;

class Leveldb_Delete_presult {
 public:


  virtual ~Leveldb_Delete_presult() throw();
  bool* success;

  _Leveldb_Delete_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Leveldb_Delete_presult& obj);

};

class LeveldbClient : virtual public LeveldbIf {
 public:
  LeveldbClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  LeveldbClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Get(std::string& _return, const std::string& key);
  void send_Get(const std::string& key);
  void recv_Get(std::string& _return);
  bool Set(const std::string& key, const std::string& value);
  void send_Set(const std::string& key, const std::string& value);
  bool recv_Set();
  bool Open(const std::string& filename);
  void send_Open(const std::string& filename);
  bool recv_Open();
  bool Close();
  void send_Close();
  bool recv_Close();
  bool Delete(const std::string& key);
  void send_Delete(const std::string& key);
  bool recv_Delete();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class LeveldbProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<LeveldbIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (LeveldbProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Set(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Open(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Close(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Delete(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  LeveldbProcessor(boost::shared_ptr<LeveldbIf> iface) :
    iface_(iface) {
    processMap_["Get"] = &LeveldbProcessor::process_Get;
    processMap_["Set"] = &LeveldbProcessor::process_Set;
    processMap_["Open"] = &LeveldbProcessor::process_Open;
    processMap_["Close"] = &LeveldbProcessor::process_Close;
    processMap_["Delete"] = &LeveldbProcessor::process_Delete;
  }

  virtual ~LeveldbProcessor() {}
};

class LeveldbProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  LeveldbProcessorFactory(const ::boost::shared_ptr< LeveldbIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< LeveldbIfFactory > handlerFactory_;
};

class LeveldbMultiface : virtual public LeveldbIf {
 public:
  LeveldbMultiface(std::vector<boost::shared_ptr<LeveldbIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~LeveldbMultiface() {}
 protected:
  std::vector<boost::shared_ptr<LeveldbIf> > ifaces_;
  LeveldbMultiface() {}
  void add(boost::shared_ptr<LeveldbIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void Get(std::string& _return, const std::string& key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Get(_return, key);
    }
    ifaces_[i]->Get(_return, key);
    return;
  }

  bool Set(const std::string& key, const std::string& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Set(key, value);
    }
    return ifaces_[i]->Set(key, value);
  }

  bool Open(const std::string& filename) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Open(filename);
    }
    return ifaces_[i]->Open(filename);
  }

  bool Close() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Close();
    }
    return ifaces_[i]->Close();
  }

  bool Delete(const std::string& key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Delete(key);
    }
    return ifaces_[i]->Delete(key);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class LeveldbConcurrentClient : virtual public LeveldbIf {
 public:
  LeveldbConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  LeveldbConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Get(std::string& _return, const std::string& key);
  int32_t send_Get(const std::string& key);
  void recv_Get(std::string& _return, const int32_t seqid);
  bool Set(const std::string& key, const std::string& value);
  int32_t send_Set(const std::string& key, const std::string& value);
  bool recv_Set(const int32_t seqid);
  bool Open(const std::string& filename);
  int32_t send_Open(const std::string& filename);
  bool recv_Open(const int32_t seqid);
  bool Close();
  int32_t send_Close();
  bool recv_Close(const int32_t seqid);
  bool Delete(const std::string& key);
  int32_t send_Delete(const std::string& key);
  bool recv_Delete(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
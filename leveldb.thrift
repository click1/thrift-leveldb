namespace cpp LevelDB

service Leveldb {
    string Get(1:string key),
    bool Set(1:string key, 2:string value);
    bool Open(1:string filename);
    bool Close();
    bool Delete(1:string key)
}

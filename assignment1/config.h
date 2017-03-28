#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class Config
{
public:
    static Config* get_instance();
    void set_absolute_path(string filename);
    void load();
    string get_value(string key);
    string get_absolute_path();
    void set_value(string key, string value);
    void destroy();
    void save();
    void change_file(string filename);


private:
    Config(){}
    ~Config(){}
    void open();
    void close();
    string filename;
    fstream config_file;
    map<string, string> config_map;
    vector<string> keys;
    static Config* instance;
};

#endif // CONFIG_H
